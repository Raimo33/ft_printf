/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 11:14:44 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char			*ft_itoa_base(int n, char *base);
unsigned int	nbrlen(long long n, unsigned int base);
int				ft_atoi(const char *nptr);
size_t			ft_strlen(const char *c);
int				ft_printf(const char *str, ...);
char			*ft_strdup(char *src);
int				add_padding(char *str, char padding_char, int padding);
void			fill_c(va_list args, char **tmp_str);
void			fill_percent(char **tmp_str);
void			fill_dixx(va_list args, char **tmp_str, char *str);
void			fill_p(va_list args, char **tmp_str);
char			*ft_strcpy(char *dest, char *src);
int				putstr(char *str);


#endif