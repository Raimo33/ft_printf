/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:17:33 by craimond          #+#    #+#             */
/*   Updated: 2023/10/26 11:17:35 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*prec_str(int prec, long long n, int base)
{
	char	*tmp_str1;

	if (prec > (int)f_nbrlen(n, base) - (n < 0))
		prec -= (int)f_nbrlen(n, base) - (n < 0);
	else
		prec = 0;
	tmp_str1 = malloc(sizeof(char) * (prec + 1));
	tmp_str1[prec] = '\0';
	while (--prec >= 0)
		tmp_str1[prec] = '0';
	return (tmp_str1);
}
