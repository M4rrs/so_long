/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:17:40 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:27:02 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_hit_d(t_data *data, int h, int w)
{
	if (data->map[h + 1][w] == '>' || data->map[h + 1][w] == '<'
		|| data->map[h + 1][w] == 'v' || data->map[h + 1][w] == '^')
	{
		data->map[h + 1][w] = 'P';
		data->map[h][w] = '0';
		data->hit = 1;
	}
}

void	check_hit_u(t_data *data, int h, int w)
{
	if (data->map[h - 1][w] == '>' || data->map[h - 1][w] == '<'
		|| data->map[h - 1][w] == 'v' || data->map[h - 1][w] == '^')
	{
		data->map[h - 1][w] = 'P';
		data->map[h][w] = '0';
		data->hit = 1;
	}
}

void	check_hit_l(t_data *data, int h, int w)
{
	if (data->map[h][w - 1] == '>' || data->map[h][w - 1] == '<'
		|| data->map[h][w - 1] == 'v' || data->map[h][w - 1] == '^')
	{
		data->map[h][w - 1] = 'P';
		data->map[h][w] = '0';
		data->hit = 1;
	}
}

void	check_hit_r(t_data *data, int h, int w)
{
	if (data->map[h][w + 1] == '>' || data->map[h][w + 1] == '<'
		|| data->map[h][w + 1] == 'v' || data->map[h][w + 1] == '^')
	{
		data->map[h][w + 1] = 'P';
		data->map[h][w] = '0';
		data->hit = 1;
	}
}

void	check_hit(int key, t_data *data)
{
	int	w;
	int	h;

	w = data->pos_x;
	h = data->pos_y;
	if (key == 1)
		check_hit_d(data, h, w);
	else if (key == 0)
		check_hit_l(data, h, w);
	else if (key == 2)
		check_hit_r(data, h, w);
	else if (key == 13)
		check_hit_u(data, h, w);
}
