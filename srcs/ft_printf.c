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
	int return1 = ft_printf("%-11d\n", 42);
	int return2 = printf("%-11d\n", 42);
	printf("return ft: %d\nreturn real: %d", return1, return2);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	int				padding;
	int				output_len;
	int				chars_written;
	void			*tmp;
	char			*str_tmp;
	int				tmp_i;
	unsigned int	tmp_ui;
	unsigned char	c;
	short			is_minus;

	i = 0;
	output_len = 0;
	chars_written = 0;
	is_minus = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		while (str[i] != '%' && str[i] != '\0')
			i++;
		chars_written += write(1, str, i);
		str += i;
		if (*str != '\0')
			str++;
		while (*str == '-')
		{
			is_minus = 1;
			str++;
		}
		if (ft_isdigit(*str))
		{
			while (*str == '0')
				str++; //nel bonus aggiungere una flag
			padding = ft_atoi(str);
			str += ft_nbrlen(padding, 10);
			if (*str == 'c')
				output_len = 1;
			else if (*str == '%')
				padding = 0;
			else if (*str == 's')
			{
				tmp = ft_strdup(va_arg(args, char *));
				output_len = ft_strlen((char *)tmp);
			}
			else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
			{
				tmp_i = va_arg(args, int);
				tmp = &tmp_i;
				if (*str == 'd' || *str == 'i')
					output_len = ft_nbrlen(tmp_i, 10);
				else
					output_len = ft_nbrlen(tmp_i, 16);
			}
			else if (*str == 'u')
			{
				tmp_ui = va_arg(args, unsigned int);
				tmp = &tmp_ui;
				output_len = ft_nbrlen(tmp_ui, 10);
			}
			else if (*str == 'p')
			{
				tmp = va_arg(args, void *);
				output_len = ft_nbrlen((long long)tmp, 16) + 2;
			}
			if (padding > output_len)
				padding -= output_len;
			if (is_minus == 0)
			{
				while (padding-- > 0)
					chars_written += write(1, " ", 1);
			}
		}
		if (*str == 'c')
		{
			c = (unsigned char)va_arg(args, int);
			chars_written += write(1, &c, 1);
		}
		else if (*str == '%')
			chars_written += write(1, "%", 1);
		else if (*str == 's')
			chars_written += write(1, tmp, ft_strlen(tmp));
		else if (*str == 'd' || *str == 'i')
		{
			str_tmp = ft_itoa(*(int *)tmp);
			chars_written += write(1, str_tmp, ft_strlen(str_tmp));
			free(str_tmp);
		}
		else if (*str == 'x' || *str == 'X')
		{
			if (*str == 'x')
				ft_putnbr_base(*(int *)tmp, "0123456789abcdef");
			else if (*str == 'X')
				ft_putnbr_base(*(int *)tmp, "0123456789ABCDEF");
			chars_written += ft_nbrlen(*(int *)tmp, 16);
		}
		else if (*str == 'p')
		{
			chars_written += ft_nbrlen((long long)tmp, 16) + write(1, "0x", 2);
			ft_putnbr_base((long long)tmp, "0123456789abcdef");
		}
		if (is_minus == 1)
		{
			while (padding-- > 0)
				chars_written += write(1, " ", 1);
		}
		i = 0;
	}
	va_end(args);
	return (chars_written);
}
