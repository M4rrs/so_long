/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:37:56 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 15:36:44 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	if_enemy(char **dup, t_data *data, int h, int w)
{
	if (data->map[h][w] == '^' || data->map[h][w] == 'v'
		|| data->map[h][w] == '>' || data->map[h][w] == '<')
	{
		dup = kill_player(dup, data, h, w);
		if (data->hit == 0)
			dup = update_enemy(dup, h, w);
	}
}

char **duplicate_map(t_data *data)
{
	int	i;
	char **arr;

	arr = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < data->height)
	{
		arr[i] = ft_strdup(data->map[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	check_enemy(t_data *data)
{
	int	h;
	int	w;
	char	**dup;

	dup = duplicate_map(data);
	data->loop++;
	h = 0;
	if (data->loop == 40)
	{
		while (h < data->height)
		{
			w = 0;
			while (w < data->width - 1)
			{
				if_enemy(dup, data, h, w);
				w++ ;
			}
			h++;
		}
		data->loop = 0;
	}
	free_map(data);
	data->map = dup;
	print_map(data);
}