/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m4rrs <m4rrs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:41:55 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/29 18:42:33 by m4rrs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_file(char *file)
{
	char *file_end;

	file_end = ".ber";
	if (ft_strrncmp(file, file_end, 4))
		return (1);
	return (0);
}

void	key_hook(int key, t_data *data)
{
	update_move(key, data);
	if (key == 53)
		close_game(key, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(1, "Error: Input a map file", 24);
		exit(EXIT_FAILURE);
	}
	else if (valid_file(argv[1]))
	{
		write(1, "Error: Map file must end with '.ber'", 37);
		exit(EXIT_FAILURE);
	}
	initialize_data(&data);
	process_input(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_x * 32, data.win_y * 32, "SO_LONG");
	display_game(&data);
}