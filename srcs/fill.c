/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:54:24 by craimond          #+#    #+#             */
/*   Updated: 2023/10/20 11:11:36 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fill_c(va_list args, char **tmp_str)
{
	*tmp_str = malloc(2);
	*tmp_str[0] = (unsigned char)va_arg(args, int);
	*tmp_str[1] = '\0';
}

void	fill_percent(char **tmp_str)
{
	*tmp_str = malloc(2);
	*tmp_str[0] = '%';
	*tmp_str[1] = '\0';
}

void	fill_dixx(va_list args, char **tmp_str, char *str)
{
	int n;

	n = va_arg(args, int);
	if (*str == 'd' || *str == 'i')
		*tmp_str = ft_itoa_base(n, "0123456789");
	else if (*str == 'x')
		*tmp_str = ft_itoa_base(n, "0123456789abcdef");
	else if (*str == 'X')
		*tmp_str = ft_itoa_base(n, "0123456789ABCDEF");
}

void	fill_p(va_list args, char **tmp_str)
{
	void *p;
	char *s;
	
	p = va_arg(args, void *);
	if (p == NULL)
		*tmp_str = "(null)";
	else
	{
		s = ft_itoa_base((long long)p, "0123456789abcdef");
		*tmp_str = malloc(sizeof(char) * (ft_strlen(s) + 3));
		*tmp_str[0] = '0';
		*tmp_str[1] = 'x';
		ft_strcpy(*tmp_str + 2, s);
	}
}
