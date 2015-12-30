/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:39:00 by                   #+#    #+#             */
/*   Updated: 2015/12/30 06:28:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_checklen(char **tab, int y)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(tab[i]);
	while (i < y && (len == (int)ft_strlen(tab[i])))
		i++;
	if (i == y)
		return (1);
	return (0);
}

int		ft_checkarray(char **tab, int *y, int *x)
{
	*y = 0;
	while (tab[*y])
	{
		*x = 0;
		while (tab[*y][*x])
		{
			if (tab[*y][*x] != 'o' && tab[*y][*x] != '.')
				return (0);
			*x += 1;
		}
		*y += 1;
	}
	if (ft_checklen(tab, *y))
		return (1);
	return (0);
}

