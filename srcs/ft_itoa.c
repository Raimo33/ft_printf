/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:43 by craimond          #+#    #+#             */
/*   Updated: 2023/10/15 12:49:23 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	nbr_len(long n);
/*
int	main(void)
{
	int n = 132220;
	printf("n: %d\nstr: %s\n", n, ft_itoa(n));
}*/

char	*ft_itoa(int n)
{
	char	*str;
	int		n_len;
	long	n_long;

	n_long = n;
	n_len = nbr_len(n_long);
	str = malloc((n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n_long == 0)
		str[0] = '0';
	if (n_long < 0)
	{
		n_long *= -1;
		str[0] = '-';
	}
	str[n_len] = '\0';
	while (n_long > 0)
	{
		str[n_len-- - 1] = (n_long % 10) + 48;
		n_long /= 10;
	}
	return (str);
}

static int	nbr_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
