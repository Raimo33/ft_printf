/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:03:31 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 23:06:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int write_p(void *tmp)
{
	long long i;

	i = (long long)tmp;
	free(tmp);
	if (tmp == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		ft_putnbr_base((long long)tmp, "0123456789abcdef");
		return (ft_nbrlen((long long)tmp, 16) + 2);
	}
}
