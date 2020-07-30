#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wsallei <wsallei@student.21-school.ru>     +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2020/07/26 22:36:33 by wsallei           #+#    #+#             *#
#*   Updated: 2020/07/26 22:36:52 by wsallei          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

.PHONY: all clean fclean re bonus

NAME = libftprintf.a

LIBFT = ./libft/libft.a

SRC_DIR = ./src

SRCS =	./src/ft_printf.c\
		./src/utils.c\
		./src/parser.c\
		./src/print_c.c\
		./src/print_di.c\
		./src/print_p.c\
		./src/print_s.c\
		./src/print_u.c\
		./src/print_x.c\

OB = $(SRCS:c=o)

CFLAG = -c -Wall -Wextra -Werror

all: $(NAME)

%.o: $(SRC_DIR)%.c
	gcc $(CFLAG) -I./includes $< 

$(NAME): $(OB)
		make  -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OB)

clean:
		make clean -C ./libft
		rm -f $(OB)

fclean: clean
		make fclean -C ./libft
		rm -f $(NAME)

re: fclean all
