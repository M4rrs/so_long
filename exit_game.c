/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:54:31 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/02 14:40:49 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	while (i < data->height)
		free(data->map[i++]);
	free(data->map);
	data = NULL;
	exit(0);
	return (0);
}