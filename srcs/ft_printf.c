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

// int	main(void)
// {
// 	char *ptr = malloc(42);
// 	int c;
// 	int return1 = ft_printf("%-p", &c);
// 	write(1, "\n", 1);
// 	int return2 = printf("%-p", &c);
// 	printf("\nreturn ft: %d\nreturn real: %d\n", return1, return2);
// }

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	int				padding;
	int				output_len;
	int				chars_written;
	char			*tmp_str;
	short			is_minus;
	char			padding_char;
	int				precision;

	i = 0;
	output_len = 0;
	chars_written = 0;
	is_minus = 0;
	padding_char = ' ';
	precision = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		while (*str != '%' && *str != '\0')
			chars_written += write(1, str++, 1);
		if (*str == '\0')
        	break;
		if (*(str + 1) != '\0')
			str++;
		while (*str == '-')
		{
			is_minus = 1;
			str++;
		}
		while (*str == '0')
		{
			padding_char = '0';
			str++;
		}
		padding = ft_atoi(str);
		if (padding > 0)
			str += nbrlen(padding, 10);
		while (*str == '.')
			str++;
		precision = ft_atoi(str);
		if (precision > 0)
			str += nbrlen(precision, 10);
		if (*str == 'c')
			tmp_str = fill_c(&args);
		else if (*str == '%')
		{
			padding = 0;
			tmp_str = ft_strdup("%");
		}
		else if (*str == 's')
			tmp_str = fill_s(&args, precision);
		else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
			tmp_str = fill_dixx(&args, (char *)str, precision);
		else if (*str == 'u')
			tmp_str = fill_u(&args, precision);
		else if (*str == 'p')
			tmp_str = fill_p(&args);
		output_len = f_strlen(tmp_str);
		if (padding > output_len)
			padding -= output_len;
		else
			padding = 0;
		if (is_minus == 0)
			chars_written += add_padding((char *)str, padding_char, padding);
		chars_written += write(1, tmp_str, output_len);
		if (is_minus == 1)
			chars_written += add_padding((char *)str, padding_char, padding);
		free(tmp_str);
		str++;
		i = 0;
	}
	va_end(args);
	return (chars_written);
}

