/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 23:28:44 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char			*ft_itoa(int n);
int				ft_atoi(const char *nptr);
int				ft_printf(const char *str, ...);
int				ft_isdigit(int c);
unsigned int	ft_nbrlen(long long n, unsigned int base);
void			ft_putnbr_base(long long nbr, char *base);
size_t			ft_strlen(const char *c);
int				ft_printf(const char *str, ...);
char			*ft_strdup(char *src);
int				outputlen_s(va_list *args, void *tmp);
int				outputlen_dixx(va_list *args, char *str, void *tmp);
int				outputlen_u(va_list *args, void *tmp);
int				outputlen_p(va_list *args, void *tmp);
int				add_padding(char *str, char padding_char, int padding);
int				write_s(void *tmp);
int				write_di(void *tmp);
int				write_xx(void *tmp, char *str);
int				write_u(void *tmp);
int 			write_p(void *tmp);


#endif