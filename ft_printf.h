/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 16:19:46 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

int				ft_printf(const char *str, ...);
char			*fill_c(va_list *args);
char			*fill_dixx(va_list *args, const char *str, int precision);
char			*fill_p(va_list *args);
char			*fill_s(va_list *args, int precision, short is_precision);
char			*fill_u(va_list *args, int precision);
int				add_padding(char *str, unsigned int padding, unsigned char padding_char);
char			*precision_str(int precision, long long n, int base);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(const char *s1, const char *s2);
int				f_strlen(char *s);
unsigned short	f_nbrlen(long long n, unsigned int base);
unsigned short	f_unbrlen(unsigned long long n, unsigned int base);
char			*ft_itoa_base(long long n, char *base);
char			*ft_utoa_base(unsigned long long n, char *base);
int				f_atoi(const char *str);

#endif
