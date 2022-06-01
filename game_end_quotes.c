/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:03:54 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/01 10:07:54 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	death_quote(void)
{
	ft_putstr_fd("+==================================+\n", 1);
	ft_putstr_fd("|      THE FOX HAS BEEN SLAIN.     |\n", 1);
	ft_putstr_fd("+==================================+\n", 1);
}

void	win_quote(void)
{
	ft_putstr_fd("+==================================+\n", 1);
	ft_putstr_fd("|    FOXY ESCAPED! CONGRATS! <3    |\n", 1);
	ft_putstr_fd("+==================================+\n", 1);
}