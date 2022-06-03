/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:54:31 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:26:07 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_map(data);
	data = NULL;
	exit(0);
	return (0);
}
