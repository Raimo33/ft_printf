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

unsigned short	f_nbrlen(long long n, ui base)
{
	short	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}

unsigned short	f_unbrlen(unsigned long long n, ui base)
{
	short	i;

	i = 0;
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}
