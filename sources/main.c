/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:32:16 by                   #+#    #+#             */
/*   Updated: 2016/01/05 15:56:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

char	**ft_tabcpy(char **dst, char **src, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	**ft_getarray(int fd)
{
	char		*line;
	char		**temp;
	char		**tab;
	int			state;
	int			i;

	i = 0;
	tab = NULL;
	state = 1;
	while (state == 1)
	{
		state = get_next_line(fd, &line);
		temp = tab;
		tab = (char **)malloc(sizeof(char *) * (i + 1));
		if (i > 0)
			tab = ft_tabcpy(tab, temp, i);
		tab[i] = ft_strdup(line);
		i++;
		ft_memdel((void **)&line);
		ft_memdel((void **)(char *)&temp);
	}
	tab[i] = NULL;
	return (tab);
}

int			ft_game(char *path, int speed)
{
	int			fd;
	s_array		array;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	array.tab = ft_getarray(fd);
	if (!(ft_checkarray(array.tab, &array.pt_max.y, &array.pt_max.x)))
		return (0);
	ft_conways(array, speed);
	while (--array.pt_max.y)
		ft_memdel((void **)&array.tab[array.pt_max.y]);
	ft_memdel((void **)array.tab);
	return (1);
}

int			main(int argc, char **argv)
{
	int error;
	int i;

	if (argc > 1 && argc < 4)
	{
		if (argc == 2)
		{
			if ((error = ft_game(argv[1], 500 * 1000)) == -1)
			{
				ft_putstr("ERROR : Bad path\n\n");
				return (0);
			}
			else if (error == 0)
			{
				ft_putstr("ERROR : Bad array\n\n");
				return (0);
			}
			else
				return (0);
		}
		if (argc == 3)
		{
			i = 0;
			while (argv[2][i] && ft_isdigit(argv[2][i]))
				i++;
			if (i == (int)ft_strlen(argv[2]))
			{
				if ((error = ft_game(argv[1], ft_atoi(argv[2]) * 1000)) == -1)
				{
					ft_putstr("ERROR : Bad path\n\n");
					return (0);
				}
				else if (error == 0)
				{
					ft_putstr("ERROR : Bad array\n\n");
					return (0);
				}
				else
					return (0);
			}
			else
				ft_putstr("ERROR : Bad speed\n\n");
		}
	}
	ft_putstr("Using :\n\tParam 1 : path of array\n \
	Param 2 : speed -> 1000 for 1s (not obligatory)\n\n");
	return (0);
}
