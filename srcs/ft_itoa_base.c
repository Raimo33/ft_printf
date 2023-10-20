/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:32:43 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 10:59:19 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa_base(int n, char *base)
{
	char			*str;
	unsigned int	n_len;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	n_len = nbrlen(n, base_len);
	str = malloc((n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[n_len] = '\0';
	while (n > 0)
	{
		str[n_len-- - 1] = base[n % (int)base_len];
		n /= (int)base_len;
	}
	return (str);
}

unsigned int	nbrlen(long long n, unsigned int base)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= base;
		i++;
	}
	return (i + 1);
}
