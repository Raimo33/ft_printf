/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:17:56 by craimond          #+#    #+#             */
/*   Updated: 2023/10/23 11:15:37 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*precision_str(int precision, long long n, int base)
{
	char	*tmp_str1;

	if (precision > (int)f_nbrlen(n, base) - (n < 0))
		precision -= (int)f_nbrlen(n, base) - (n < 0);
	else
		precision = 0;
	tmp_str1 = malloc(sizeof(char) * (precision + 1));
	tmp_str1[precision] = '\0';
	while (--precision >= 0)
		tmp_str1[precision] = '0';
	return (tmp_str1);
}
