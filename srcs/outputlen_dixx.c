/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputlen_dixx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:32:45 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 22:27:36 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	outputlen_dixx(va_list *args, char *str, void *tmp)
{
	int i;
	
	i = va_arg(*args, int);
	tmp = (void *)&i;
	if (*str == 'd' || *str == 'i')
		return(ft_nbrlen(i, 10));
	return(ft_nbrlen(i, 16));
}