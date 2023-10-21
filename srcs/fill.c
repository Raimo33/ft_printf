/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:54:24 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 11:47:58 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_c(va_list *args)
{
	char	*tmp_str;

	tmp_str = malloc(sizeof(char) * 2);
	tmp_str[0] = (unsigned char)va_arg(*args, int);
	tmp_str[1] = '\0';
	return (tmp_str);
}

char	*fill_s(va_list *args, int precision, short is_precision)
{
	char	*tmp_str;

	tmp_str = ft_strdup(va_arg(*args, char *));
	if (tmp_str == NULL)
	{
		free(tmp_str);
		return ("(null)");
	}
	if (precision < f_strlen(tmp_str) && is_precision == 1)
		tmp_str[precision] = '\0';
	return (tmp_str);
}

char	*fill_u(va_list *args, int precision)
{
	unsigned int	n;
	char			*tmp_str;
	char			*new_str;

	n = va_arg(*args, unsigned int);
	tmp_str = ft_itoa_base(n, "0123456789");
	new_str = ft_strjoin(precision_str(precision, n, 10), tmp_str);
	free(tmp_str);
	return (new_str);
}

char	*fill_dixx(va_list *args, const char *str, int precision)
{
	int		n;
	char	*tmp_str;
	char	*new_str;

	n = va_arg(*args, int);
	if (*str == 'd' || *str == 'i')
	{
		tmp_str = ft_itoa_base(n, "0123456789");
		new_str = ft_strjoin(precision_str(precision, n, 10), tmp_str);
	}
	else if (*str == 'x')
	{
		tmp_str = ft_itoa_base(n, "0123456789abcdef");
		new_str = ft_strjoin(precision_str(precision, n, 16), tmp_str);
	}
	else if (*str == 'X')
	{
		tmp_str = ft_itoa_base(n, "0123456789ABCDEF");
		new_str = ft_strjoin(precision_str(precision, n, 16), tmp_str);
	}
	else
		return (NULL);
	free(tmp_str);
	return (new_str);
}

char	*fill_p(va_list *args)
{
	void	*p;
	char	*s;
	char	*tmp_str;

	p = va_arg(*args, void *);
	if (p == NULL)
		return ("(nil)");
	else
	{
		s = ft_itoa_base((long long)p, "0123456789abcdef");
		tmp_str = malloc(sizeof(char) * (f_strlen(s) + 3));
		tmp_str[0] = '0';
		tmp_str[1] = 'x';
		ft_strcpy(tmp_str + 2, s);
		free(s);
	}
	return (tmp_str);
}
