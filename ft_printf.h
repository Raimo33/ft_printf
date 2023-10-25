/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/25 15:38:25 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct flags
{
	short			is_minus;
	short			is_precision;
	short			is_space;
	short			is_hash;
	short			is_plus;
	unsigned char	padding_char;
	unsigned int	chars_written;
}					t_flags;

int				ft_printf(const char *str, ...);
char			*fill_c(va_list *args);
char			*fill_dixx(va_list *args, const char *str, int prec, t_flags *f);
char			*fill_p(va_list *args);
char			*fill_s(va_list *args, int precision, t_flags *f);
char			*fill_u(va_list *args, int precision, t_flags *f);
int				add_padding(char *str, unsigned int padding, char **tmp_str, t_flags *f);
char			*precision_str(int precision, long long n, int base);
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
