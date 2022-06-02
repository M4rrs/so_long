/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:27:51 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/02 17:51:48 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_data(t_data *data)
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
	data->hit = 0;
	data->frames = 0;
	// data->player = 0;
	// data->exit = 0;
	// data->items = 0;
}