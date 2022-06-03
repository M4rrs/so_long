/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:55:04 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:18:55 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	update_r(char **dup, int h, int w)
{
	if (dup[h][w + 1] == '0')
	{
		dup[h][w + 1] = '>';
		dup[h][w] = '0';
	}
	else if (dup[h][w + 1] != '0')
		dup[h][w] = '<';
}

void	update_l(char **dup, int h, int w)
{
	if (dup[h][w - 1] == '0')
	{
		dup[h][w - 1] = '<';
		dup[h][w] = '0';
	}
	else if (dup[h][w - 1] != '0')
		dup[h][w] = '>';
}

void	update_u(char **dup, int h, int w)
{
	if (dup[h - 1][w] == '0')
	{
		dup[h - 1][w] = '^';
		dup[h][w] = '0';
	}
	else if (dup[h - 1][w] != '0')
		dup[h][w] = 'v';
}

void	update_d(char **dup, int h, int w)
{
	if (dup[h + 1][w] == '0')
	{
		dup[h + 1][w] = 'v';
		dup[h][w] = '0';
	}
	else if (dup[h + 1][w] != '0')
		dup[h][w] = '^';
}

char	**update_enemy(char	**dup, int h, int w)
{
	if (dup[h][w] == '>')
		update_r(dup, h, w);
	else if (dup[h][w] == '<')
		update_l(dup, h, w);
	else if (dup[h][w] == 'v')
		update_d(dup, h, w);
	else if (dup[h][w] == '^')
		update_u(dup, h, w);
	return (dup);
}
