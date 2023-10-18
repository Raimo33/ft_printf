# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <craimond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:29:01 by craimond          #+#    #+#              #
#    Updated: 2023/10/17 11:31:06 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_putsmth.c srcs/ft_putnbr_base.c srcs/ft_putnbr_fd.c srcs/ft_strlen.c
OBJS = srcs/ft_printf.o srcs/ft_putsmth.o srcs/ft_putnbr_base.o srcs/ft_putnbr_fd.o srcs/ft_strlen.o
HEADER = headers/ft_printf.h

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

%.o: %.c ${HEADER}
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus:

.PHONY: all clean fclean re bonus