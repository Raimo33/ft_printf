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
// 	int return1 = ft_printf("%024p", NULL);
// 	write(1, "\n", 1);
// 	int return2 = printf("%024p", NULL);
// 	//printf("return ft: %d\nreturn real: %d", return1, return2);
// }

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	int				padding;
	int				output_len;
	int				chars_written;
	void			*tmp;
	short			is_minus;
	char			padding_char;
	unsigned char	c;

	i = 0;
	output_len = 0;
	chars_written = 0;
	is_minus = 0;
	padding_char = ' ';
	va_start(args, str);
	while (*str != '\0')
	{
		tmp = NULL;
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
		padding = ft_atoi(str); //controllo numero
		str += ft_nbrlen(padding, 10); //skippo numero
		////////////////CONTROLLO LUNGHEZZA OUTPUT//////////////////////////////
		if (*str == 'c')
			output_len = 1;
		else if (*str == '%')
			padding = 0;
		else if (*str == 's')
			output_len = outputlen_s(&args, tmp);
		else if (*str == 'd' || *str == 'i' || *str == 'x' || *str == 'X')
			output_len = outputlen_dixx(&args, (char *)str, tmp);
		else if (*str == 'u')
			output_len = outputlen_u(&args, tmp);
		else if (*str == 'p')
			output_len = outputlen_p(&args, tmp);
		///////////////////CALCOLO PADDING//////////////////////////////////////
		if (padding > output_len)
			padding -= output_len;
		else
			padding = 0;
		if (is_minus == 0)
			chars_written += add_padding((char *)str, padding_char, padding);
		//////////////////////////WRITE////////////////////////////// 
		if (*str == 'c')
		{
			c = (unsigned char)va_arg(args, int);
			chars_written += write(1, &c, 1);
		}
		else if (*str == '%')
			chars_written += write(1, "%", 1);
		else if (*str == 's')
			chars_written += write_s(tmp);
		else if (*str == 'd' || *str == 'i')
			chars_written += write_di(tmp);
		else if (*str == 'u')
			chars_written += write_u(tmp);
		else if (*str == 'x' || *str == 'X')
			chars_written += write_xx(tmp, (char *)str);
		else if (*str == 'p')
			chars_written += write_p(tmp);
		if (is_minus == 1)
			chars_written += add_padding((char *)str, padding_char, padding);
		str++;
		i = 0;
	}
	va_end(args);
	return (chars_written);
}
