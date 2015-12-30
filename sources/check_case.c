/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <cchameyr@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 07:21:21 by cchameyr          #+#    #+#             */
/*   Updated: 2015/12/30 08:08:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_checkcasefirstline(char **tab, s_pt pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (tab[pt.y + 1][pt.x] == 'o')
			match++;
		if (tab[pt.y][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y + 1][pt.x + 1] == 'o')
			match++;
	}
	else if (pt.x > 0)
	{
		if (tab[pt.y + 1][pt.x] == 'o')
			match++;
		if (tab[pt.y][pt.x - 1] == 'o')
			match++;
		if (tab[pt.y][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y + 1][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y + 1][pt.x - 1] == 'o')
			match++;
	}
	return (match);
}

int		ft_checkcaselastline(char **tab, s_pt pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (tab[pt.y - 1][pt.x] == 'o')
			match++;
		if (tab[pt.y][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y - 1][pt.x + 1] == 'o')
			match++;
	}
	else if (pt.x > 0)
	{
		if (tab[pt.y - 1][pt.x] == 'o')
			match++;
		if (tab[pt.y][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y][pt.x - 1] == 'o')
			match++;
		if (tab[pt.y - 1][pt.x - 1] == 'o')
			match++;
		if (tab[pt.y - 1][pt.x + 1] == 'o')
			match++;
	}
	return (match);
}

int		ft_checkcasemiddle(char **tab, s_pt pt)
{
	int match;

	match = 0;
	if (pt.x == 0)
	{
		if (tab[pt.y - 1][pt.x] == 'o')
			match++;
		if (tab[pt.y + 1][pt.x] == 'o')
			match++;
		if (tab[pt.y][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y - 1][pt.x + 1] == 'o')
			match++;
		if (tab[pt.y + 1][pt.x + 1] == 'o')
			match++;
	}
	else if (pt.x > 0)
		match = ft_checkmiddlemiddle(tab, pt);
	return (match);
}

int		ft_checkmiddlemiddle(char **tab, s_pt pt)
{
	int		match;

	match = 0;
	if (tab[pt.y - 1][pt.x] == 'o')
		match++;
	if (tab[pt.y + 1][pt.x] == 'o')
		match++;
	if (tab[pt.y][pt.x - 1] == 'o')
		match++;
	if (tab[pt.y][pt.x + 1] == 'o')
		match++;
	if (tab[pt.y - 1][pt.x - 1] == 'o')
		match++;
	if (tab[pt.y - 1][pt.x + 1] == 'o')
		match++;
	if (tab[pt.y + 1][pt.x + 1] == 'o')
		match++;
	if (tab[pt.y + 1][pt.x - 1] == 'o')
		match++;
	return (match);
}

int		ft_checkfullcase(s_array *array, s_pt pt)
{
	if (pt.y == 0)
		return (ft_checkcasefirstline(array->tab, pt));
	if (pt.y > 0 && pt.y < array->pt_max.y - 1)
		return (ft_checkcasemiddle(array->tab, pt));
	if (pt.y == array->pt_max.y - 1)
		return (ft_checkcaselastline(array->tab, pt));
	return (0);
}
