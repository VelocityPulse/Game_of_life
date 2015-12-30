/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:32:16 by                   #+#    #+#             */
/*   Updated: 2015/12/30 15:08:01 by                  ###   ########.fr       */
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

int			ft_game(char *path)
{
	int			fd;
	s_array		array;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	array.tab = ft_getarray(fd);
	if (!(ft_checkarray(array.tab, &array.pt_max.y, &array.pt_max.x)))
		return (0);
	ft_conways(array);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_game(argv[1]))
			ft_putstr("error\n");
		else
		{
			ft_putstr("victoire\n");
			return (0);
		}
	}
	ft_putstr("precisez un fichier\n");
	return (0);
}
