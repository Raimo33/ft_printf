/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 14:23:45 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

#include <stdio.h>

char			*ft_itoa_base(int n, char *base);
unsigned int	nbrlen(long long n, unsigned int base);
int				ft_atoi(const char *nptr);
int				f_strlen(char *s);
int				ft_printf(const char *str, ...);
char			*ft_strdup(char *src);
int				add_padding(char *str, char padding_char, int padding);
char			*fill_c(va_list *args);
char			*fill_dixx(va_list *args, char *str, int precision);
char			*fill_p(va_list *args);
char			*fill_s(va_list *args, int precision);
char			*fill_u(va_list *args, int precision);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(const char *s1, const char *s2);
char 			*precision_str(int precision, long long n, int base);

#endif