/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:46:54 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 22:51:24 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_s(void *tmp)
{
	if (tmp == NULL)
		return(write(1, "(null)", 6));
	else
		return(write(1, (char *)tmp, ft_strlen((char *)tmp)));
	free(tmp);
}
