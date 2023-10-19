/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:12:30 by craimond          #+#    #+#             */
/*   Updated: 2023/10/17 11:58:49 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_base(char *base, int len);

void	ft_putnbr_base(long long nbr, char *base)
{
	int	len;

	len = (int)ft_strlen(base);
	if (check_base(base, len) == 0 || len <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= len)
		ft_putnbr_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
}

static int	check_base(char *base, int len)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (n < len && base[i + n] != '\0')
		{
			if (base[i] == base[i + n])
				return (0);
			n++;
		}
		n = 1;
		i++;
	}
	return (1);
}
