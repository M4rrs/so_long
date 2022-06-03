/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:41:55 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:19:26 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	valid_file(char *file)
{
	char	*file_end;

	file_end = ".ber";
	if (ft_strrncmp(file, file_end, 4))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		data.message = "ERROR: Input a map file.\n";
		return_error(&data);
	}
	else if (valid_file(argv[1]))
	{
		data.message = "ERROR: Map file must end with '.ber'\n";
		return_error(&data);
	}
	initialize_data(&data);
	process_input(&data, argv[1]);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.width + 4) * 32,
			data.height * 32, "SO_LONG");
	display_game(&data);
}
