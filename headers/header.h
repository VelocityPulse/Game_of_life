/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 12:37:20 by                   #+#    #+#             */
/*   Updated: 2015/12/29 13:25:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "structs.h"

# define YOLO ft_putstr("\nYOLO\n");
# define YOLO1 ft_putstr("YOLO1-\n");
# define YOLO2 ft_putstr("YOLO2--\n");
# define PAUSE while(1){sleep(20);}

char	ft_capture(char *path);
int		ft_game(char *path);

#endif
