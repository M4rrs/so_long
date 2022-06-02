/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:11:07 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/02 14:14:59 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// int	map_height(t_data *data, int fd)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL || ft_strlen(line) == 1)
// 			break ;
// 		data->height++ ;
// 		free(line);
// 	}
// 	return (data->height);
// }

void check_width(t_data *data, int i)
{
	int	width;

	width = ft_strlen(data->map[i]);
	if (data->width != width && (i > 0))
	{
		data->message = "ERROR. Map is not rectangular.\n";
		return_error(data);
	}
	data->width = width;

}
void read_error(char *buff, t_data *data)
{
	free(buff);
	buff = NULL;
	return_error(data);
}

void	process_input(t_data *data, char *file)
{
	char	*buff;
	int		bytes;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);

	buff = malloc(1000 * sizeof(char));
	if (!buff)
		read_error(buff, data);
	bytes = read(fd, buff, 1000);
	buff[bytes] = '\0';
	// data->map = (char **)malloc(sizeof(char *) * map_height(data, fd) + 1);
	data->map = ft_split(buff, '\n');
	if (!data->map)
		return_error(data);

	i = 0;
	while (data->map[i])
	{
		//printf("map %d: %s\n", i, data->map[i]);
		check_width(data, i);
		data->height++;
		i++;
	}
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	printf("GETTING\n");
	// 	printf("line: %s\n", line);
	// 	if (line == NULL)
	// 		break ;
	// 	if (line)
	// 	{
	// 		check_width(data, i, line);
	// 		printf("HERE\n");
	// 		data->map[i++] = ft_strdup(line);
	// 	}
	// 	else
	// 		read_error(line, data);
	// 	free(line);
	// }
	if(valid_map(data))
		return_error(data);
}