/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:38 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 13:17:52 by craimond         ###   ########.fr       */
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

#endif