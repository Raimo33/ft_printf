# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <craimond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:29:01 by craimond          #+#    #+#              #
#    Updated: 2023/10/19 23:32:10 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/ft_putnbr_base.c srcs/ft_strlen.c srcs/ft_nbrlen.c srcs/ft_atoi.c srcs/ft_itoa.c srcs/ft_isdigit.c srcs/ft_strdup.c srcs/add_padding.c srcs/outputlen_dixx.c srcs/outputlen_p.c srcs/outputlen_s.c srcs/outputlen_u.c srcs/write_di.c srcs/write_p.c srcs/write_s.c srcs/write_u.c srcs/write_xx.c
OBJS = ${SRCS:.c=.o}
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