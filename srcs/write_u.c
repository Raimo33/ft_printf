/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:01:06 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 23:27:46 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_u(void *tmp)
{
	unsigned int i;
	
	i = *(unsigned int *)tmp;
	ft_putnbr_base(i, "0123456789");
	free(tmp);
	return (ft_nbrlen(i, 10));
}