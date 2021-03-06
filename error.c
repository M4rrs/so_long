/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnorazma <nnorazma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:24:46 by nnorazma          #+#    #+#             */
/*   Updated: 2022/06/03 19:26:10 by nnorazma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	return_error(t_data *data)
{
	if (data->message)
		ft_putstr_fd(data->message, 1);
	else
		ft_putstr_fd("ERROR.\n", 1);
	exit(EXIT_FAILURE);
}
