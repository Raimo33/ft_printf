/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:39:33 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 22:24:09 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	outputlen_u(va_list *args, void *tmp)
{
	unsigned int ui;

	ui = va_arg(*args, unsigned int);
	tmp = &ui;
	return(ft_nbrlen(ui, 10));
}
