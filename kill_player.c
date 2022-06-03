/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:10:15 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:24:29 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// This function only kills the player if
// it enemy runs into the player.
char	**kill_lr(char **dup, t_data *data, int h, int w)
{
	if (dup[h][w] == '>' && dup[h][w + 1] == 'P')
	{
		dup[h][w] = '0';
		data->hit = 1;
	}
	else if (dup[h][w] == '<' && dup[h][w - 1] == 'P')
	{
		dup[h][w] = '0';
		data->hit = 1;
	}
	return (dup);
}

char	**kill_ud(char **dup, t_data *data, int h, int w)
{
	if (dup[h][w] == '^' && dup[h - 1][w] == 'P')
	{
		dup[h][w] = '0';
		data->hit = 1;
	}
	else if (dup[h][w] == 'v' && dup[h + 1][w] == 'P')
	{
		dup[h][w] = '0';
		data->hit = 1;
	}
	return (dup);
}

char	**kill_player(char **dup, t_data *data, int h, int w)
{
	if (dup[h][w] == '>' || dup[h][w] == '<')
		kill_lr(dup, data, h, w);
	else if (dup[h][w] == 'v' || dup[h][w] == '^')
		kill_ud(dup, data, h, w);
	return (dup);
}
