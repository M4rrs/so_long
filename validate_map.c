/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:58 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/28 15:22:07 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int valid_char(t_data *data, int h, int w)
{
	if (data->map[h][w] != '0' && data->map[h][w] != '1' 
		&& data->map[h][w] != 'C' && data->map[h][w] != 'E' 
		&& data->map[h][w] != 'P' && data->map[h][w] != '<'
		&& data->map[h][w] != '>' && data->map[h][w] != '^'
		&& data->map[h][w] != 'v')
		return (0);
	return (1);
}

void	add_items(t_data *data, int h, int w)
{
	if (data->map[h][w] == 'C')
		data->items++;
	if (data->map[h][w] == 'E')
		data->exit = 1;
	if (data->map[h][w] == 'P')
		data->player = 1;
}

void	valid_border(t_data *data)
{
	int i;

	i = 0;
	while (i < data->width - 1)
	{
		if (data->map[0][i] != '1')
			return_error();
		if (data->map[data->height - 1][i] != '1')
			return_error();
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1')
			return_error();
		if (data->map[i][data->width - 1] != '1')
			return_error();
		i++;
	}
}

int	valid_map(t_data *data)
{	
	int	h;
	int	w;

	h = 0;
	while (h < data->height)
	{
		w = 0;
		while (w < data->width - 1)
		{
			if (!valid_char(data, h, w))
				return (0);
			add_items(data, h, w);
			w++;
		}
		h++;
	}
	if (!check_cep(data))
		return (0);
	valid_border(data);
}