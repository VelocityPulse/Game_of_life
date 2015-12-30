/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:37:20 by                   #+#    #+#             */
/*   Updated: 2015/12/30 06:33:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

# define YOLO ft_putstr("\nYOLO\n");
# define YOLO1 ft_putstr("YOLO1-\n");
# define YOLO2 ft_putstr("YOLO2--\n");
# define PAUSE while(1){sleep(20);}

typedef struct	t_pt
{
	int		x;
	int		y;
}				s_pt;

typedef struct t_array
{
	char	**tab;
	s_pt	pt_max;
}				s_array;

char	**ft_tabcpy(char **dst, char **src, int n);
char	**ft_getarray(int fd);
int		ft_game(char *path);

int		ft_checklen(char **tab, int y);
int		ft_checkarray(char **tab, int *y, int *x);

#endif
