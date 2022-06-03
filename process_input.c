/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:11:07 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:21:29 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	check_width(t_data *data, int i)
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

void	read_error(char *buff, t_data *data)
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
	data->map = ft_split(buff, '\n');
	free(buff);
	if (!data->map)
		return_error(data);
	i = 0;
	while (data->map[i])
	{
		check_width(data, i);
		data->height++;
		i++;
	}
	if (valid_map(data))
		return_error(data);
}
