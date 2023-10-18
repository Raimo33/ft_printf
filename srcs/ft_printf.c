/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:28:55 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 15:29:24 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		chars_written;

	chars_written = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
			chars_written += write(1, str, 1);
		else
			chars_written += ft_putsmth((char *)++str, args);
		while (*str >= '0' && *str <= '9')
			str++;
		str++;
	}
	va_end(args);
	return (chars_written);
}

// int main(void)
// {
// 	char *ptr = malloc(0);
// 	char c = 'A';
// 	int return1 = ft_printf("%44c\n", 'a');
// 	int return2 = printf("%44c\n", 'a');
	
// 	printf("return ft: %i\nreturn real: %i", return1, return2);
// }
