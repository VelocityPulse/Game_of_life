#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cchameyr <cchameyr@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/27 12:40:31 by cchameyr          #+#    #+#             *#
#*   Updated: 2015/12/29 13:25:51 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =	game

SRCS =	sources/main.c \
		sources/get_next_line.c \

OBJS =	main.o \
		get_next_line.o \

LIB =	libft/libft.a

CC =	gcc

FLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIB)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)

$(LIB):
	make -C ./libft/

clean:
	rm -f $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all
