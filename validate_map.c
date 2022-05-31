/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:51:58 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/31 17:24:35 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int valid_char(t_data *data, int h, int w)
{
	if (data->map[h][w] != '0' && data->map[h][w] != '1' 
		&& data->map[h][w] != 'C' && data->map[h][w] != 'E' 
		&& data->map[h][w] != 'P' && data->map[h][w] != '<'
		&& data->map[h][w] != '>' && data->map[h][w] != '^'
		&& data->map[h][w] != 'v')
		return (1);
	return (0);
}

// void	add_items(t_data *data, int h, int w)
// {
// 	if (data->map[h][w] == 'C')
// 		data->items++;
// 	if (data->map[h][w] == 'E')
// 		data->exit = 1;
// 	if (data->map[h][w] == 'P')
// 		data->player = 1;
// }

int	valid_border(t_data *data)
{
	int i;

	i = 0;
	while (i < data->width - 1)
	{
		if (data->map[0][i] != '1')
			return(1);
		if (data->map[data->height - 1][i] != '1')
			return(1);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->map[i][0] != '1')
			return(1);
		if (data->map[i][data->width - 1] != '1')
			return(1);
		i++;
	}
	return (0);
}

void	check_cep(t_data *data)
{
	if (char_exists(data, 'C'))
		data->message = "ERROR. No apples in the map D: \n";
	if (char_exists(data, 'E'))
		data->message = "ERROR. No exits in the map.\n";
	if (char_exists(data, 'P'))
		data->message = "ERROR. Where's little foxy? \n";
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
			if (valid_char(data, h, w))
				data->message = "ERROR. Invalid char exists in map.\n";
			w++;
		}
		h++;
	}
	if (valid_border(data))
		data->message = "ERROR. Map border is invalid.\n";
	check_cep(data);
	if (data->message)
		return_error();
}