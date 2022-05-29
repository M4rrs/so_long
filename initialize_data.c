/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m4rrs <m4rrs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:27:51 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/30 00:19:01 by m4rrs            ###   ########.fr       */
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
	// data->player = 0;
	// data->exit = 0;
	// data->items = 0;
}