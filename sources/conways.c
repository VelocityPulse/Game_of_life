/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 06:30:35 by                   #+#    #+#             */
/*   Updated: 2015/12/30 08:26:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int			ft_modifyarray(s_array *array, s_array *new_array, s_pt pt)
{
	int		case_used;

	case_used = ft_checkfullcase(array, pt);
	if (array->tab[pt.y][pt.x] == 'o')
	{
		if (case_used == 2 || case_used == 3)
		{
			new_array->tab[pt.y][pt.x] = array->tab[pt.y][pt.x];
			return (0);
		}
		new_array->tab[pt.y][pt.x] = '.';
		return (1);
	}
	if (array->tab[pt.y][pt.x] == '.')
	{
		if (case_used != 3)
		{
			new_array->tab[pt.y][pt.y] = array->tab[pt.y][pt.x];
			return (0);
		}
		new_array->tab[pt.y][pt.x] = 'o';
		return (1);
	}
	return (0);
}

int			ft_conways(s_array array)
{
	s_array new_array;
	int		modify;
	s_pt	pt;

	new_array = ft_initarray(ft_arrayalloc(array.pt_max));
	modify = 1;
	while (modify)
	{
		modify = 0;
		pt.x = 0;
		while (pt.y < array.pt_max.y)
		{
			pt.x = 0;
			if (ft_utility(array)) // a coder
			{
				while (pt.x++ < array.pt_max.y)
					modify = ft_modifyarray(&array, &new_array, pt);
			}
			pt.y++;
		}
	}
	return (1);
}
