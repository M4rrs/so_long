/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m4rrs <m4rrs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:31:01 by nnorazma          #+#    #+#             */
/*   Updated: 2022/05/29 23:54:41 by m4rrs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strrncmp(char *s1, char *s2, int n)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = n;
	while((*s1 && i > n) || (*s2 && j > 0))
	{
		if(s1[i] != s2[j])
			return (1);
		i-- ;
		j-- ;
	}
	return (0);
}

int	char_exists(t_data *data, char c)
{
	
}