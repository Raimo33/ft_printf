/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:46:26 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 10:23:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	add_padding(char *str, unsigned int padding)
{
	int chars_written;

	chars_written = 0;
	if (*str == 'p' || *str == 'c' || *str == 's')
	{
		while (padding-- > 0)
			chars_written += (write(1, " ", 1));
	}
	else
	{
		while (padding-- > 0)
			chars_written += (write(1, &g_padding_char, 1));
	}
	return (chars_written);
}
