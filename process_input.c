/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:11:07 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/24 15:19:05 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(t_data *data, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || ft_strlen(line) == 1)
			break ;
		data->height++ ;
		free(line);
	}
	return (data->height);
}

int	process_input(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * map_height(data, fd) + 1);

}