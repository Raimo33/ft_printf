/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_nbrlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:17:46 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 10:17:46 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned short	f_nbrlen(long long n, unsigned int base)
{
	short	i;

	i = -1;
	if (n < 0 && ++i >= 0)
		n *= -1;
	i--;
	while (n >= base && ++i > 0)
		n /= base;
	return (i + 1);
}

unsigned short	f_unbrlen(unsigned long long n, unsigned int base)
{
	short	i;

	i = -1;
	while (n >= base && ++i >= 0)
		n /= base;
	return (i + 1);
}
