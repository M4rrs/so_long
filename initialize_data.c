/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:27:51 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/28 15:26:47 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_data(t_data *data)
{
	data->width = 0;
	data->height = 0;
	data->win_x = 0;
	data->win_y = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->player = 0;
	data->exit = 0;
	data->items = 0;
}