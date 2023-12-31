# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: craimond <craimond@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:29:01 by craimond          #+#    #+#              #
#    Updated: 2023/10/26 14:43:36 by craimond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/f_strlen.c srcs/ft_itoa_base.c srcs/ft_strdup.c srcs/add_pad.c srcs/fill.c srcs/ft_strcpy.c srcs/prec_str.c srcs/ft_strjoin.c srcs/f_nbrlen.c srcs/f_atoi.c srcs/ft_strtrim.c srcs/f_strtoupper.c
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

bonus: all

.PHONY: all clean fclean re bonus