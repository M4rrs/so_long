/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:33:33 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/02 18:01:21 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	animate_player(t_data *data)
{
	char	*ani;
	char	*ani2;

	ani = "./assets/foxy2";
	ani2 = "./assets/foxy3";

	if (data->frames < 15)
	{
		data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
						ani, &data->img_w, &data->img_h);
	}
}