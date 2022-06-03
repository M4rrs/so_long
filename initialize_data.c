/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:27:51 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:24:44 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_data(t_data *data)
{
	data->message = NULL;
	data->width = 0;
	data->height = 0;
	data->win_x = 0;
	data->win_y = 0;
	data->pos_x = 0;
	data->pos_y = 0;
	data->img_w = 0;
	data->img_h = 0;
	data->frames = 0;
	data->hit = 0;
	data->loop = 0;
	data->moves = 0;
}
