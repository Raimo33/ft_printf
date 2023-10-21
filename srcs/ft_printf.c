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

static int			until_identifier(unsigned int *chars_written, unsigned int *padding, unsigned int *precision, const char *str);
static unsigned int	handle_identifier(va_list *args, const char *str, unsigned int precision, unsigned int *padding);

short			g_is_minus;
short			g_is_precision;
unsigned char	g_padding_char;

//#include <stdio.h>
// int	main(void)
// {
// 	char *ptr = malloc(42);
// 	int c;
// 	int return1 = ft_printf(" %c ", 42);
// 	write(1, "\n", 1);
// 	int return2 = printf(" %c ", 42);
// 	//printf("\nreturn ft: %d\nreturn real: %d\n", return1, return2);
// }

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	chars_written;
	unsigned int	precision;
	unsigned int	padding;

	chars_written = 0;
	precision = 0;
	g_is_minus = 0;
	g_padding_char = ' ';
	g_is_precision = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		str += until_identifier(&chars_written, &padding, &precision, str);
		if (*str == '\0')
			break ;
		chars_written += handle_identifier(&args, str, precision, &padding);
		str++;
	}
	va_end(args);
	return (chars_written);
}

static int	until_identifier(unsigned int *chars_written, unsigned int *padding, unsigned int *precision, const char *str)		
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		*chars_written += write(1, &str[i++], 1);
	if (str[i] == '\0')
		return (i);
	while (str[++i] == '-')
		g_is_minus = 1;
	i--;
	while (str[++i] == '0')
		g_padding_char = '0';
	*padding = f_atoi(str + i);
	if (*padding > 0)
		i += f_nbrlen(*padding, 10);
	i--;
	while (str[++i] == '.')
		g_is_precision = 1;
	*precision = f_atoi(str + i);
	if (*precision > 0 || str[i] == '0')
		i += f_nbrlen(*precision, 10);
	return (i);
}

static unsigned int	handle_identifier(va_list *args, const char *str, unsigned int precision, unsigned int *padding)
{
	char			*tmp_str;
	unsigned int	output_len;
	unsigned int	chars_written;

	tmp_str = NULL;
	chars_written = 0;
	if (*str == 'c')
		tmp_str = fill_c(args);
	else if (*str == '%')
		tmp_str = ft_strdup("%");
	else if (*str == 's')
		tmp_str = fill_s(args, precision, g_is_precision);
	else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
		tmp_str = fill_dixx(args, str, precision);
	else if (*str == 'u')
		tmp_str = fill_u(args, precision);
	else if (*str == 'p')
		tmp_str = fill_p(args);
	output_len = f_strlen(tmp_str);
	if (*padding > output_len && *str != '%')
		*padding -= output_len;
	else
		*padding = 0;
	if (g_is_minus == 0)
		chars_written += add_padding((char *)str, *padding, g_padding_char);
	chars_written += write(1, tmp_str, output_len);
	if (g_is_minus == 1)
		chars_written += add_padding((char *)str, *padding, g_padding_char);
	free(tmp_str);
	return (chars_written);
}
