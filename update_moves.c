/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:57:42 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 15:14:21 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	update_moves(t_data *data, int p_x, int p_y)
{
	if (data->map[p_y][p_x] != '1' && data->map[p_y][p_x] != 'E')
	{
		data->map[data->pos_y][data->pos_x] = '0';
		data->map[p_y][p_x] = 'P';
		data->pos_x = p_x;
		data->pos_y = p_y;
	}
	else if (data->map[p_y][p_x] == 'E')
	{
		if (!char_exists(data, 'C'))
		{
			win_quote();
			exit_game(data);
		}
	}
	data->moves++;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	print_map(data);
}

int	key_hook(int key, t_data *data)
{
	if (key == 13)
		update_moves(data, data->pos_x, data->pos_y - 1);
	else if (key == 1)
		update_moves(data, data->pos_x, data->pos_y + 1);
	else if (key == 0)
		update_moves(data, data->pos_x - 1, data->pos_y);
	else if (key == 2)
		update_moves(data, data->pos_x + 1, data->pos_y);
	else if (key == 53)
	{
		ft_putstr_fd("GAME OVER.\n", 1);
		exit_game(data);
	}
	return (0);
}
int	render_loop(t_data	*data)
{
	// print_map(data);
	data->frames++;
	check_enemy(data);
	if (data->hit == 0)
	{
		animate_player(data);
	}
	return (0);
}

void	display_game(t_data *data)
{
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, exit_game, data);
	mlx_loop_hook(data->mlx_ptr, render_loop, data);
	mlx_loop(data->mlx_ptr);
}