/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:33:33 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 12:09:02 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	animate_2(t_data *data)
{
	char	*ani3;
	char	*ani4;

	ani3 = "./assets/foxy4.xpm";
	ani4 = "./assets/foxy5.xpm";
	if (data->frames > 30 && data->frames < 60)
	{
		if (data->frames < 45)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
						ani3, &data->img_w, &data->img_h);
		}
		else if (data->frames < 60)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
						ani4, &data->img_w, &data->img_h);
			data->frames = 0;
		}
	}
}

void	animate_player(t_data *data)
{
	char	*ani;
	char	*ani2;

	ani = "./assets/foxy2.xpm";
	ani2 = "./assets/foxy3.xpm";
	if (data->frames < 15)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->grass, data->pos_x * 32, data->pos_y * 32);
		data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
						ani, &data->img_w, &data->img_h);
	}
	else if (data->frames < 30)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->grass, data->pos_x * 32, data->pos_y * 32);
		data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
						ani2, &data->img_w, &data->img_h);
	}
	else if (data->frames < 60)
		animate_2(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->fox, data->pos_x * 32, data->pos_y * 32);
}