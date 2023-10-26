/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/26 12:06:56 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef unsigned int	ui;

typedef struct flags
{
	short			is_minus;
	short			is_prec;
	short			is_space;
	short			is_hash;
	short			is_plus;
	unsigned char	pad_ch;
	unsigned int	chars_written;
}						t_flags;

int				ft_printf(const char *str, ...);
char			*fill_c(va_list *args);
char			*fill_di(va_list *args, int prec, t_flags *f);
char			*fill_xx(va_list *args, const char *str, int prec, t_flags *f);
char			*fill_p(va_list *args);
char			*fill_s(va_list *args, int prec, t_flags *f);
char			*fill_u(va_list *args, int prec, t_flags *f);
int				add_pad(char *str, unsigned int pad, char **tmp_str, t_flags *f);
char			*prec_str(int prec, long long n, int base);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(const char *s1, const char *s2);
int				f_strlen(char *s);
void			f_strtoupper(char *str);
unsigned short	f_nbrlen(long long n, unsigned int base);
unsigned short	f_unbrlen(unsigned long long n, unsigned int base);
char			*ft_itoa_base(long long n, char *base);
char			*ft_utoa_base(unsigned long long n, char *base);
int				f_atoi(const char *str);
char			*ft_strtrim(const char *s1, const char *set);

#endif
