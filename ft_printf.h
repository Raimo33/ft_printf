/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 15:57:37 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

#include <stdio.h>

int				ft_printf(const char *str, ...);
char			*fill_c(va_list *args);
char			*fill_dixx(va_list *args, char *str, int precision);
char			*fill_p(va_list *args);
char			*fill_s(va_list *args, int precision);
char			*fill_u(va_list *args, int precision);
int				add_padding(char *str, int padding);
char 			*precision_str(int precision, long long n, int base);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(const char *s1, const char *s2);
int				f_strlen(char *s);
unsigned int	f_nbrlen(long long n, unsigned int base);
char			*ft_itoa_base(long long n, char *base);

#endif