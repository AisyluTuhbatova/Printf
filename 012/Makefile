# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crossart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 19:28:19 by crossart          #+#    #+#              #
#    Updated: 2021/01/26 19:28:21 by crossart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

SRC = ft_printf.c \
	ft_char.c \
	ft_flags.c \
	ft_hex.c \
	ft_int.c \
	ft_pointer.c \
	ft_string.c \
	ft_un_int.c \
	ft_itoa.c \
	ft_strchr.c \
	ft_strlen.c \
	ft_strdup.c

OBJ = $(SRC:.c=.o)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC);
	ar cr $(NAME) $(OBJ);
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
