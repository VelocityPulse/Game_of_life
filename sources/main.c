/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:32:16 by                   #+#    #+#             */
/*   Updated: 2015/12/29 18:50:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

char	**ft_getarray(int fd, int *y)
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
			tab = ft_memcpy(tab, temp, i);
		tab[i] = ft_strdup(line);
		i++;
		ft_memdel((void **)&line);
		ft_memdel((void **)(char *)&temp);
	}
	*y = i;
	tab[i] = NULL;
	return (tab);
}

int			ft_game(char *path)
{
	int			fd;
	s_array		array;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	array.tab = ft_getarray(fd, &array.pt_max.y);
//	if (!(ft_checkarray(array.tab)))
		return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_game(argv[1]))
			ft_putstr("error\n");
		else
			return (0);
	}
	ft_putstr("precisez un fichier\n");
	return (0);
}
