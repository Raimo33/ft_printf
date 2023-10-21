/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:37:09 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 10:27:52 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	is_space(const char *str);

int	f_atoi(const char *str)
{
	int	num_meno;
	int	num;

	num_meno = 0;
	num = 0;
	while (!is_space(str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			num_meno++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *(str) - 48;
		str++;
	}
	if (num_meno % 2 == 1)
	{
		num = -num;
	}
	return (num);
}

static int	is_space(const char *str)
{
	if (*str == ' ' || *str == '\f' || *str == '\n')
		return (0);
	if (*str == '\t' || *str == '\v' || *str == '\r')
		return (0);
	return (1);
}
