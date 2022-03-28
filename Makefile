# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sriyani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 10:43:21 by sriyani           #+#    #+#              #
#    Updated: 2022/03/28 10:43:25 by sriyani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = so_long.h

OBJ = so_long.c\
	  so_long_utils.c\
	  so_long_utils2.c\
	  so_long_utils3.c\
	  get_next_line.c\
	  get_next_line_utils.c\
	  ft_printf.c\
	  
CC = cc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@


all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	@/bin/rm -f $(OBJC)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
