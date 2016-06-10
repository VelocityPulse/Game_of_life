/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 15:33:48 by                   #+#    #+#             */
/*   Updated: 2016/06/10 11:50:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_display(s_array array)
{
	s_pt pt;

	system("clear");
	pt.y = 0;
	while (pt.y < array.pt_max.y)
	{
		pt.x = 0;
		while (pt.x < array.pt_max.x)
			ft_putchar(array.tab[pt.y][pt.x++]);
		ft_putchar('\n');
		pt.y++;
	}
}
