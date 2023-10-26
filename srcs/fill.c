/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:54:24 by craimond          #+#    #+#             */
/*   Updated: 2023/10/26 14:52:09 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*fill_s(va_list *args, int prec, t_flags *f)
{
	char	*tmp_str;

	tmp_str = ft_strdup(va_arg(*args, char *));
	if (tmp_str == NULL)
	{
		free(tmp_str);
		if (prec < 6 && (*f).is_prec == 1)
			return (ft_strdup(""));
		tmp_str = ft_strdup("(null)");
	}
	if (prec < f_strlen(tmp_str) && (*f).is_prec == 1)
		tmp_str[prec] = '\0';
	return (tmp_str);
}

char	*fill_u(va_list *args, int prec, t_flags *f)
{
	t_ui	n;
	char	*tmp_str;
	char	*new_str;

	n = va_arg(*args, t_ui);
	tmp_str = ft_itoa_base(n, "0123456789");
	new_str = ft_strjoin(prec_str(prec, n, 10), tmp_str);
	free(tmp_str);
	if (prec < f_strlen(new_str) && (*f).is_prec == 1 && n == 0)
		new_str[prec] = '\0';
	return (new_str);
}

char	*fill_di(va_list *args, int prec, t_flags *f)
{
	int		n;
	char	*tmp_str;
	char	*new_str;
	char	*newest_str;

	n = va_arg(*args, int);
	tmp_str = ft_itoa_base(n, "0123456789");
	new_str = ft_strjoin(prec_str(prec, n, 10), tmp_str + (n < 0));
	if (n < 0)
		newest_str = ft_strjoin(ft_strdup("-"), new_str);
	else
	{
		if ((*f).is_plus == 1 && (*f).pad_ch == ' ')
			newest_str = ft_strjoin(ft_strdup("+"), new_str);
		else
			newest_str = ft_strdup(new_str);
	}
	if (prec < f_strlen(newest_str) && (*f).is_prec == 1 && n == 0)
		newest_str[prec] = '\0';
	free(new_str);
	free(tmp_str);
	return (newest_str);
}

char	*fill_xx(va_list *args, const char *str, int prec, t_flags *f)
{
	int		n;
	char	*tmp_str;
	char	*new_str;
	char	*newest_str;

	n = va_arg(*args, int);
	tmp_str = ft_utoa_base((t_ui)n, "0123456789abcdef");
	if ((*f).is_hash == 1 && (t_ui)n != 0 && (*f).pad_ch == ' ')
	{
		new_str = ft_strjoin(ft_strdup("0x"), tmp_str);
		newest_str = ft_strjoin(prec_str(prec, (t_ui)n, 16), new_str);
		free(new_str);
	}
	else
		newest_str = ft_strjoin(prec_str(prec, (t_ui)n, 16), tmp_str);
	if (*str == 'X')
		f_strtoupper(newest_str);
	if (prec < f_strlen(newest_str) && (*f).is_prec == 1 && n == 0)
		newest_str[prec] = '\0';
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
