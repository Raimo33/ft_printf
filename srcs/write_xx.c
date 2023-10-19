/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:57:30 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 23:00:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_xx(void *tmp, char *str)
{
	int i;

	i = *(int *)tmp;
	if (*str == 'x')
		ft_putnbr_base(i, "0123456789abcdef");
	else if (*str == 'X')
		ft_putnbr_base(i, "0123456789ABCDEF");
	free(tmp);
	return(ft_nbrlen(i, 16));
}
