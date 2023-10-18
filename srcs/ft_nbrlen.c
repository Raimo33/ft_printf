/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:30:37 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 14:51:20 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int	ft_nbrlen(long long n, unsigned int base)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}
