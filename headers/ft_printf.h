/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:27:02 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 10:34:53 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
void			ft_putnbr_base(long long nbr, char *base);
int				ft_putsmth(char *str, va_list args);
size_t			ft_strlen(const char *c);
void			ft_putnbr_fd(int n, int fd);
unsigned int	ft_nbrlen(long long n, unsigned int base);

#endif
