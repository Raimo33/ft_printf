/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:28:55 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 10:28:49 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				chars_written;

	chars_written = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str != '%')
			chars_written += write(1, str, 1);
		else
			chars_written += ft_putsmth((char *)++str, args);
		str++;
	}
	va_end(args);
	return (chars_written);
}
/*
int main(void)
{
	char *ptr = malloc(sizeof(char) * 42);
	char c = 'A';
	int return1 = ft_printf("%d%p%c\n", 123412, ptr, '\0');
	int return2 = printf("%d%p%c\n", 123412, ptr, '\0');
	
	printf("return ft: %i\nreturn real: %i", return1, return2);
}*/
