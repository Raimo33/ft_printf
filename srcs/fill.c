/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:54:24 by craimond          #+#    #+#             */
/*   Updated: 2023/10/25 12:09:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_s(va_list *args, int precision, flags *f)
{
	char	*tmp_str;

	tmp_str = ft_strdup(va_arg(*args, char *));
	if (tmp_str == NULL)
	{
		free(tmp_str);
		if (precision < 6 && (*f).is_precision == 1) //da sostituire la flag is_precision con precision >= 0 (parte da -1)
			return (ft_strdup(""));
		tmp_str = ft_strdup("(null)");
	}
	if (precision < f_strlen(tmp_str) && (*f).is_precision == 1) //da sostituire la flag is_precision con precision >= 0 (parte da -1)
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

char	*fill_dixx(va_list *args, const char *str, int precision, flags *f)
{
	int		n;
	char	*tmp_str;
	char	*new_str;
	char	*newest_str;

	n = va_arg(*args, int);
	if (*str == 'd' || *str == 'i')
	{
		tmp_str = ft_itoa_base(n, "0123456789");
		new_str = ft_strjoin(precision_str(precision, n, 10), tmp_str + (n < 0));
		if (n < 0)
		{
			newest_str = ft_strjoin(ft_strdup("-"), new_str);
			free(new_str);
		}
		else
		{
			if ((*f).is_plus == 1 && (*f).padding_char == ' ')
			{
				newest_str = ft_strjoin(ft_strdup("+"), new_str);
				free(new_str);
			}
			else
				newest_str = new_str;
		}
		
	}
	else if (*str == 'x')
	{
		tmp_str = ft_utoa_base((unsigned int)n, "0123456789abcdef");
		if ((*f).is_hash == 1 && (unsigned int)n != 0 && (*f).padding_char == ' ')
		{
			new_str = ft_strjoin(ft_strdup("0x"), tmp_str);
			newest_str = ft_strjoin(precision_str(precision, (unsigned int)n, 16), new_str);
			free(new_str);
		}
		else	
			newest_str = ft_strjoin(precision_str(precision, (unsigned int)n, 16), tmp_str);
	}
	else if (*str == 'X') //usare to_upper
	{
		tmp_str = ft_utoa_base((unsigned int)n, "0123456789ABCDEF");
		if ((*f).is_hash == 1 && (unsigned int)n != 0 && (*f).padding_char == ' ')
		{
			new_str = ft_strjoin(ft_strdup("0X"), tmp_str);
			newest_str = ft_strjoin(precision_str(precision, (unsigned int)n, 16), new_str);
			free(new_str);
		}
		else
			newest_str = ft_strjoin(precision_str(precision, (unsigned int)n, 16), tmp_str);
	}
	else
		return (NULL);
	if (precision < f_strlen(newest_str) && (*f).is_precision == 1 && n == 0) //da sostituire la flag is_precision con precision >= 0 (parte da -1)
		newest_str[precision] = '\0';
	free(tmp_str);
	return (newest_str);
}

char	*fill_p(va_list *args)
{
	long long	p;
	char		*s;
	char		*tmp_str;

	p = (unsigned long long)va_arg(*args, void *);
	if (p == 0)
		return (ft_strdup("(nil)"));
	else
	{
		s = ft_utoa_base(p, "0123456789abcdef");
		tmp_str = malloc(sizeof(char) * (f_strlen(s) + 3));
		tmp_str[0] = '0';
		tmp_str[1] = 'x';
		ft_strcpy(tmp_str + 2, s);
		free(s);
	}
	return (tmp_str);
}
