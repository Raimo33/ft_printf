/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:53:12 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 11:53:12 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	unt_id(t_flags *f, ui *pad, ui *prec, const char *str);
static long	han_id(t_flags *f, va_list *args, const char *str, ui prec, ui *pad);
static long	check_flags(char *str, t_flags *f, long i);
static char	*check_pad(char *str, t_flags *f, ui prec, va_list *args, ui *pad);

// #include <stdio.h>
// int	main(void)
// {
// 	int c;
// 	int return1 = ft_printf("%c", 42);
// 	write(1, "\n", 1);
// 	int return2 = printf("%c", 42);
// 	printf("\nreturn ft: %d\nreturn real: %d\n", return1, return2);
// }

int	ft_printf(const char *str, ...)
{
	va_list			args;
	t_flags			f;
	ui				prec;
	ui				pad;

	f.chars_written = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		prec = 0;
		f.is_minus = 0;
		f.pad_ch = ' ';
		f.is_prec = 0;
		f.is_space = 0;
		f.is_hash = 0;
		f.is_plus = 0;
		str += unt_id(&f, &pad, &prec, str);
		if (*str == '\0')
			break ;
		f.chars_written += han_id(&f, &args, str, prec, &pad);
		str++;
	}
	va_end(args);
	return (f.chars_written);
}

static long	unt_id(t_flags *f, ui *pad, ui *prec, const char *str)
{
	long	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		(*f).chars_written += write(1, &str[i++], 1);
	if (str[i] == '\0')
		return (i);
	i = check_flags((char *)str, f, i);
	*pad = f_atoi(str + i);
	if (*pad > 0)
		i += f_nbrlen(*pad, 10);
	i--;
	while (str[++i] == '.')
		(*f).is_prec = 1;
	while (str[i] == '0')
		i++;
	*prec = f_atoi(str + i);
	i += f_nbrlen(*prec, 10) - (*prec == 0);
	return (i);
}

static long	han_id(t_flags *f, va_list *args, const char *str, ui prec, ui *pad)
{
	char	*tmp_str;
	int		chars_written;
	int		output_len;

	tmp_str = NULL;
	chars_written = 0;
	tmp_str = check_pad((char *)str, f, prec, args, pad);
	if (*pad == 0 && (*f).is_space == 1 && *str != 's'
		&& *str != 'c' && tmp_str[0] != '-')
		chars_written += write(1, " ", 1);
	if ((*f).is_prec == 1)
		(*f).pad_ch = ' ';
	if ((*f).is_minus == 0)
		chars_written += add_pad((char *)str, *pad, &tmp_str, f);
	output_len = f_strlen(tmp_str) + (tmp_str[0] == '\0' && *str == 'c');
	chars_written += write(1, tmp_str, output_len);
	if ((*f).is_minus == 1)
		chars_written += add_pad((char *)str, *pad, NULL, f);
	free(tmp_str);
	return (chars_written);
}

static long	check_flags(char *str, t_flags *f, long i)
{
	while (str[++i] == '-' || str[i] == '0' || str[i] == ' '
		|| str[i] == '#' || str[i] == '+')
	{
		if (str[i] == '-')
			(*f).is_minus = 1;
		if (str[i] == '0')
			(*f).pad_ch = '0';
		if (str[i] == ' ')
			(*f).is_space = 1;
		if (str[i] == '#')
			(*f).is_hash = 1;
		if (str[i] == '+')
			(*f).is_plus = 1;
	}
	if ((*f).is_minus == 1)
		(*f).pad_ch = ' ';
	return (i);
}

static char	*check_pad(char *str, t_flags *f, ui prec, va_list *args, ui *pad)
{
	char			*ts;
	unsigned char	c;

	ts = NULL;
	if (*str == 'c')
		c = va_arg(*args, int);
	if (*str == 'c')
		ts = ft_strdup((char *)&c);
	else if (*str == '%')
		ts = ft_strdup("%");
	else if (*str == 's')
		ts = fill_s(args, prec, f);
	else if (*str == 'd' || *str == 'i')
		ts = fill_di(args, prec, f);
	else if (*str == 'x' || *str == 'X')
		ts = fill_xx(args, str, prec, f);
	else if (*str == 'u')
		ts = fill_u(args, prec, f);
	else if (*str == 'p')
		ts = fill_p(args);
	if (*pad > (ui)(f_strlen(ts) + (ts[0] == 0 && *str == 'c')) && *str != '%')
		*pad -= f_strlen(ts) + (ts[0] == '\0' && *str == 'c');
	else
		*pad = 0;
	return (ts);
}
