/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:12:20 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/02 17:44:25 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	get_images(t_data	*data)
{
	char	*fox;
	char	*apple;
	char	*grass;
	char	*stone;
	char	*exit;

	fox = "./assets/foxy.xpm";
	apple = "./assets/apple.xpm";
	stone = "./assets/rock.xpm";
	grass = "./assets/grass.xpm";
	exit = "./assets/exit.xpm";
	data->img->fox = mlx_xpm_file_to_image(data->mlx_ptr, fox,
					&data->img_w, &data->img_h);
	data->img->apple = mlx_xpm_file_to_image(data->mlx_ptr, apple,
					&data->img_w, &data->img_h);
	data->img->stone = mlx_xpm_file_to_image(data->mlx_ptr, stone,
					&data->img_w, &data->img_h);
	data->img->grass = mlx_xpm_file_to_image(data->mlx_ptr, grass,
					&data->img_w, &data->img_h);
	data->img->exit = mlx_xpm_file_to_image(data->mlx_ptr, exit,
					&data->img_w, &data->img_h);
}

void	print_images(t_data *data, int h, int w)
{
	if (data->map[h][w] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
							data->img->stone, data->win_x * 32,
							data->win_y * 32);
	else if (data->map[h][w] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->exit, data->win_x * 32,
						data->win_y * 32);
	else if (data->map[h][w] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->apple, data->win_x * 32,
						data->win_y * 32);
	else if (data->map[h][w] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->img->fox, data->win_x * 32,
						data->win_y * 32);
		data->pos_x = w;
		data->pos_y = h;
	}
}

void	print_map(t_data *data)
{
	// int	img_w;
	// int img_h;
	int h;
	int w;

	// img_w = 0;
	// img_h = 0;
	get_images(data);

	h = 0;
	while (data->map[h])
	{
		data->win_y = h;
		w = 0;
		while (data->map[h][w])
		{
			data->win_x = w;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
								data->img->grass, data->win_x * 32,
								data->win_y * 32);
			print_images(data, h, w);
			w++;
		}
		h++;
		
	}
}