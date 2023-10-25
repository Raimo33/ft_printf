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

static int			until_identifier(struct flags *f, unsigned int *padding, unsigned int *precision, const char *str);
static unsigned int	handle_identifier(struct flags *f, va_list *args, const char *str, unsigned int precision, unsigned int *padding);

// #include <stdio.h>
// int	main(void)
// {
// 	int c;
// 	int return1 = ft_printf("%.03s", NULL);
// 	write(1, "\n", 1);
// 	int return2 = printf("%.03s", NULL);
// 	printf("\nreturn ft: %d\nreturn real: %d\n", return1, return2);
// }

int	ft_printf(const char *str, ...)
{
	va_list			args;
	flags			f;
	unsigned int	precision;
	unsigned int	padding;

	f.chars_written = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		precision = 0;
		f.is_minus = 0;
		f.padding_char = ' ';
		f.is_precision = 0;
		f.is_space = 0;
		f.is_hash = 0;
		f.is_plus = 0;
		str += until_identifier(&f, &padding, &precision, str);
		if (*str == '\0')
			break ;
		f.chars_written += handle_identifier(&f, &args, str, precision, &padding);
		str++;
	}
	va_end(args);
	return (f.chars_written);
}

static int	until_identifier(flags *f, unsigned int *padding, unsigned int *precision, const char *str)
{
	int	i;
	int	num_zeros;

	i = 0;
	num_zeros = 0;
	while (str[i] != '%' && str[i] != '\0')
		(*f).chars_written += write(1, &str[i++], 1);
	if (str[i] == '\0')
		return (i);
	while (str[++i] == '-' || str[i] == '0' || str[i] == ' ' || str[i] == '#' || str[i] == '+') //questa roba separarla in una funzione (checkflags)
	{
		if (str[i] == '-')
			(*f).is_minus = 1;
		if (str[i] == '0')
			(*f).padding_char = '0';
		if (str[i] == ' ')
			(*f).is_space = 1;
		if (str[i] == '#')
			(*f).is_hash = 1;
		if (str[i] == '+')
			(*f).is_plus = 1;
	}
	if ((*f).is_minus == 1)
		(*f).padding_char = ' ';
	*padding = f_atoi(str + i);
	if (*padding > 0)
		i += f_nbrlen(*padding, 10);
	i--;
	while (str[++i] == '.')
		(*f).is_precision = 1; //da togliere
	while (str[i] == '0')
		i++;
	*precision = f_atoi(str + i);
	i += f_nbrlen(*precision, 10) - (*precision == 0);
	return (i);
}

static unsigned int	handle_identifier(flags *f, va_list *args, const char *str, unsigned int precision, unsigned int *padding)
{
	char			*tmp_str;
	unsigned int	output_len;
	unsigned int	chars_written;
	unsigned char	c;

	tmp_str = NULL;
	chars_written = 0;
	if (*str == 'c')
		output_len = 1;
	else if (*str == '%')
		tmp_str = ft_strdup("%");
	else if (*str == 's')
		tmp_str = fill_s(args, precision, f);
	else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
		tmp_str = fill_dixx(args, str, precision, f);
	else if (*str == 'u')
		tmp_str = fill_u(args, precision);
	else if (*str == 'p')
		tmp_str = fill_p(args);
	if (*str != 'c')
		output_len = f_strlen(tmp_str);
	if (*padding > output_len && *str != '%')
		*padding -= output_len;
	else
		*padding = 0;
	if (*padding == 0 && (*f).is_space == 1 && *str != 's' && *str != 'c')
	{
		if (tmp_str[0] == '-' && f_strlen(tmp_str) < 2)
			chars_written += write(1, " ", 1);
		else if (tmp_str[0] != '-')
			chars_written += write(1, " ", 1);
	}
	if ((*f).is_minus == 0)
		chars_written += add_padding((char *)str, *padding, &tmp_str, f);
	if (*str != 'c')
		chars_written += write(1, tmp_str, f_strlen(tmp_str));
	else
	{
		c = va_arg(*args, int);
		chars_written += write(1, &c, 1);
	}	
	if ((*f).is_minus == 1)
		chars_written += add_padding((char *)str, *padding, NULL, f);
	free(tmp_str);
	return (chars_written);
}
