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

int	main(void)
{
	char *ptr = malloc(42);
	int return1 = ft_printf("cacca%s", "www");
	write(1, "\n", 1);
	//int return2 = printf("%d", 42);
	//printf("return ft: %d\nreturn real: %d", return1, return2);
}

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

	i = 0;
	output_len = 0;
	chars_written = 0;
	is_minus = 0;
	padding_char = ' ';
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
		str += nbrlen(padding, 10);
		if (*str == 'c')
			fill_c(args, &tmp_str);
		else if (*str == '%')
		{
			padding = 0;
			fill_percent(&tmp_str);
		}	
		else if (*str == 's')
			tmp_str = ft_strdup(va_arg(args, char *));
		else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
			fill_dixx(args, &tmp_str, (char *)str);
		else if (*str == 'u')
			tmp_str = ft_itoa_base(va_arg(args, unsigned int), "0123456789");
		else if (*str == 'p')
			fill_p(args, &tmp_str);
		output_len = ft_strlen(tmp_str);
		if (padding > output_len)
			padding -= output_len;
		else
			padding = 0;
		if (is_minus == 0)
			chars_written += add_padding((char *)str, padding_char, padding);
		chars_written += putstr(tmp_str);
		free(tmp_str);
		str++;
		i = 0;
	}
	va_end(args);
	return (chars_written);
}
