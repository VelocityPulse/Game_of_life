/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pt3df.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:00:34 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/15 13:44:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pt3df		ft_add_pt3df(t_pt3df pt1, t_pt3df pt2)
{
	t_pt3df		pt3;

	pt3.x = pt1.x + pt2.x;
	pt3.y = pt1.y + pt2.y;
	pt3.z = pt1.z + pt2.z;
	return (pt3);
}
