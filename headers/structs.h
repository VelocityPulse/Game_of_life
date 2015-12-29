/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:33:36 by                   #+#    #+#             */
/*   Updated: 2015/12/27 19:20:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <stdlib.h>
#include "libft.h"

typedef struct	t_pt
{
	int		x;
	int		y;
}				s_pt;

typedef struct	t_array
{
	char	**tab;
	s_pt	pt_max;
}				s_array;

typedef struct	t_str
{
	char			str[32];
	int				index;
	struct t_str	*next;
}				s_str;

s_str	*ft_addc(s_str *begin, char c);
s_str	*ft_newlstr(void);
int		ft_indexcpt(s_str *begin);
s_str	*ft_freelstr(s_str *begin);
char	*ft_exportstr(s_str *begin);

#endif
