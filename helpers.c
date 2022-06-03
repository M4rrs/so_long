/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:31:01 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:25:31 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = n;
	while ((s1[i] && i > n) && (s2[j] && j >= 0))
	{
		if (s1[i] != s2[j])
			return (1);
		i-- ;
		j-- ;
	}
	return (0);
}

int	char_exists(t_data *data, char c)
{
	int	h;
	int	w;

	h = 0;
	while (data->map[h] != NULL)
	{
		w = 0;
		while (data->map[h][w] != '\0')
		{
			if (data->map[h][w] == c)
				return (1);
			w++;
		}
		h++;
	}
	return (0);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		free(data->map[i++]);
	free(data->map);
}
