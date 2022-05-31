/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:11:07 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/31 14:21:53 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

void check_width(t_data *data, int i, char *line)
{
	int	width;

	width = ft_strlen(line);
	if (data->width != width && (i > 0))
	{
		data->message = "ERROR. Map is not rectangular.\n";
		return_error();
	}
	data->width = width;

}
void read_error(char *line)
{
	free(line);
	line = NULL;
	return_error();
}

void	process_input(t_data *data, char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * map_height(data, fd) + 1);
	if (!data->map)
		return_error();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line)
		{
			check_width(data, i, line);
			data->map[i++] = ft_strdup(line);
		}
		else
			read_error(line);
		free(line);
	}
	if(valid_map(data));
		return_error();
}