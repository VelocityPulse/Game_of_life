/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 06:30:35 by                   #+#    #+#             */
/*   Updated: 2015/12/30 07:12:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

s_array		ft_arrayalloc(s_pt pt_max)
{
	s_array		new_array;

	new_array.tab = (char **)malloc(sizeof(char *) * (pt_max.y));
	while (new_array.pt_max.y < pt_max.y)
		new_array.tab[new_array.pt_max.y++] = ft_memalloc(pt_max.x);
	new_array.pt_max.x = pt_max.x;
	return (new_array);
}

s_array		ft_initarray(s_array new_array)
{
	int		i;

	i = 0;
	while (i < new_array.pt_max.y)
		ft_bzero(new_array.tab[i++], new_array.pt_max.x);
	return (new_array);
}

int			ft_modifyarray(s_array *array, s_array *new_array)
{
	
}

int			ft_conways(s_array array)
{
	s_array new_array;
	int		modify;
	int		case_used;
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
			if (ft_utility(array))
			{
				while (pt.x++ < array.pt_max.y)
					modify = ft_modifyarray(&array, &new_array);
			}
			pt.y++;
		}
	}
}
