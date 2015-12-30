/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 07:16:05 by                   #+#    #+#             */
/*   Updated: 2015/12/30 14:57:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

s_array		ft_arrayalloc(s_pt pt_max)
{
	s_array		new_array;

	new_array.tab = (char **)malloc(sizeof(char *) * (pt_max.y));
	while (new_array.pt_max.y < pt_max.y)
		new_array.tab[new_array.pt_max.y++] = ft_memalloc(pt_max.x);
	new_array.pt_max.y = pt_max.x;
	return (new_array);
}

s_array		ft_initarray(s_array new_array)
{
	int		i;

	i = 0;
	while (i < new_array.pt_max.y && new_array.tab[i])
		ft_bzero((void *)new_array.tab[i++], new_array.pt_max.x);
	return (new_array);
}
