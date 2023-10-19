/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputlen_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:41:13 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 22:25:55 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	outputlen_p(va_list *args, void *tmp)
{
	long long i;

	tmp = va_arg(*args, void *);
	i = (long long)tmp;
	if (tmp == NULL)
		return(5);
	else
		return(ft_nbrlen(i, 16) + 2);
}