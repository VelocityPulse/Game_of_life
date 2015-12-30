/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 06:30:35 by                   #+#    #+#             */
/*   Updated: 2015/12/30 08:05:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int			ft_modifyarray(s_array *array, s_array *new_array, s_pt pt)
{
	int		case_used;

	case_used = ft_checkfullcase(array, pt);
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
}
