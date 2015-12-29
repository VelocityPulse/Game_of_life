/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:03:45 by aperraul          #+#    #+#             */
/*   Updated: 2015/12/27 18:47:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/structs.h"

s_str	*ft_addc(s_str *begin, char c)
{
	s_str	*list;

	if (!begin)
		begin = ft_newlstr();
	list = begin;
	while (list->next)
		list = list->next;
	if (c)
	{
		if (list->index < 32)
		{
			list->str[list->index] = c;
			list->index++;
		}
		else
		{
			list->next = ft_newlstr();
			list = list->next;
			list->str[0] = c;
			list->index++;
		}
	}
	return (begin);
}

s_str	*ft_newlstr(void)
{
	s_str	*list;

	if (!(list = (s_str *)malloc(sizeof(s_str))))
		return (NULL);
	list->next = NULL;
	list->index = 0;
	ft_bzero(list->str, 32);
	return (list);
}

int		ft_indexcpt(s_str *begin)
{
	int		i;
	s_str	*list;

	i = 0;
	if (!begin)
		return (0);
	list = begin;
	while (list->next)
	{
		i += list->index;
		list = list->next;
	}
	return (i + list->index);
}

s_str	*ft_freelstr(s_str *begin)
{
	s_str	*temp1;
	s_str	*temp2;

	if (begin)
	{
		temp1 = begin;
		while (temp1->next)
		{
			temp2 = temp1->next;
			free(temp1);
			temp1 = temp2;
		}
		begin = NULL;
	}
	return (begin);
}

char	*ft_exportstr(s_str *begin)
{
	s_str	*list;
	char	*str;

	list = begin;
	if (!list)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * ft_indexcpt(begin) + 1)))
		return (NULL);
	while (list->next)
	{
		str = ft_strncat(str, list->str, list->index);
		list = list->next;
	}
	str = ft_strncat(str, list->str, list->index);
	return (str);
}
