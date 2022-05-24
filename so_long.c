/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:41:55 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/24 15:30:06 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_file(char *file)
{
	char *file_end;

	file_end = ".ber";
	//ft_strrncmp (reverse compare)
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
	process_input(&data, argv[1]);
}