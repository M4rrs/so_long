/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:51:35 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:29:36 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	death_3(t_data *data)
{
	char	*snek5;
	char	*snek6;

	snek5 = "./assets/snek_death5.xpm";
	snek6 = "./assets/snek_death6.xpm";
	if (data->frames > 80 && data->frames < 120)
	{
		if (data->frames < 100)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
					snek5, &data->img_w, &data->img_h);
		}
		else if (data->frames < 120)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
					snek6, &data->img_w, &data->img_h);
			data->frames = 0;
		}
	}
}

void	death_2(t_data *data)
{
	char	*snek3;
	char	*snek4;

	snek3 = "./assets/snek_death3.xpm";
	snek4 = "./assets/snek_death4.xpm";
	if (data->frames > 40 && data->frames < 80)
	{
		if (data->frames < 60)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
					snek3, &data->img_w, &data->img_h);
		}
		else if (data->frames < 80)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->img->grass, data->pos_x * 32, data->pos_y * 32);
			data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
					snek4, &data->img_w, &data->img_h);
		}
	}
}

void	animate_death(t_data *data)
{
	char	*snek;
	char	*snek2;

	snek = "./assets/snek_death.xpm";
	snek2 = "./assets/snek_death2.xpm";
	if (data->frames < 20)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->grass, data->pos_x * 32, data->pos_y * 32);
		data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
				snek, &data->img_w, &data->img_h);
	}
	else if (data->frames < 40)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img->grass, data->pos_x * 32, data->pos_y * 32);
		data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr,
				snek2, &data->img_w, &data->img_h);
	}
	else if (data->frames < 80)
		death_2(data);
	else if (data->frames < 120)
		death_3(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img->fox, data->pos_x * 32, data->pos_y * 32);
}
