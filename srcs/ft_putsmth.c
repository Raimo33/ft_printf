/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsmth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:47:55 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 10:32:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	put_uxx(char *str_types, va_list args);
static int	put_cdi(char *str_types, va_list args);

int	ft_putsmth(char *str, va_list args)
{
	char			*tmp_s;
	void			*tmp_ptr;

	if (*str == 's')
	{
		tmp_s = va_arg(args, char *);
		return (write(1, tmp_s, ft_strlen(tmp_s)));
	}
	else if (*str == 'c' || *str == 'd' || *str == 'i')
		return (put_cdi(str, args));
	else if (*str == 'u' || *str == 'x' || *str == 'X')
		return (put_uxx(str, args));
	else if (*str == 'p')
	{
		tmp_ptr = va_arg(args, void *);
		write(1, "0x", 2);
		ft_putnbr_base((long long)tmp_ptr, "0123456789abcdef");
		return (ft_nbrlen((long long)tmp_ptr, 16) + 2);
	}
	else
		return (write(1, str, 1));
	return (0);
}

static int	put_cdi(char *str_types, va_list args)
{
	int	tmp_i;

	if (*str_types == 'c')
	{
		tmp_i = va_arg(args, int);
		return (write(1, &tmp_i, 1));
	}
	else if (*str_types == 'd' || *str_types == 'i')
	{
		tmp_i = va_arg(args, int);
		ft_putnbr_fd(tmp_i, 1);
		return (ft_nbrlen(tmp_i, 10));
	}
	return (0);
}

static int	put_uxx(char *str_types, va_list args)
{
	unsigned int	tmp_ui;

	if (*str_types == 'u')
	{
		tmp_ui = va_arg(args, unsigned int);
		ft_putnbr_fd(tmp_ui, 1);
		return (ft_nbrlen(tmp_ui, 10));
	}
	else if (*str_types == 'x')
	{
		tmp_ui = va_arg(args, unsigned int);
		ft_putnbr_base(tmp_ui, "0123456789abcdef");
		return (ft_nbrlen(tmp_ui, 16));
	}
	else if (*str_types == 'X')
	{
		tmp_ui = va_arg(args, unsigned int);
		ft_putnbr_base(tmp_ui, "0123456789ABCDEF");
		return (ft_nbrlen(tmp_ui, 16));
	}
	return (0);
}
