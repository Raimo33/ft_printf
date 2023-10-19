# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <craimond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:29:01 by craimond          #+#    #+#              #
#    Updated: 2023/10/18 14:54:25 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_putnbr_base.c srcs/ft_strlen.c srcs/ft_nbrlen.c srcs/ft_atoi.c srcs/ft_itoa.c srcs/ft_isdigit.c srcs/ft_strdup.c
OBJS = srcs/ft_printf.o srcs/ft_putnbr_base.o srcs/ft_strlen.o srcs/ft_nbrlen.o srcs/ft_atoi.o srcs/ft_itoa.o srcs/ft_isdigit.o srcs/ft_strdup.o
HEADER = ft_printf.h

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