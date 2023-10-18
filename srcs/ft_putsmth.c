/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsmth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:47:55 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 15:28:13 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	put_uxx(char *str_types, va_list args);
static int	put_cdi(char *str_types, va_list args);

int	ft_putsmth(char *str, va_list args)
{
	char	*tmp_s;
	void	*tmp_ptr;
	int		nbr;
	int 	i;

	i = -1;
	nbr = 0;
	if (*str >= '0' && *str <= '9')
	{
		nbr = ft_atoi(str) - 1;
		while (*str >= '0' && *str <= '9')
			str++;
		if (*str == 's' || *str == 'c' || *str == 'd' || *str == 'i' || *str == 'u' || *str == 'X' || *str == 'x' || *str == 'p') //accorciare con strcmp
		{
			while (++i < nbr)
				write(1, " ", 1);
		}
		else
			nbr = 0;
	}
	if (*str == 's')
	{
		tmp_s = va_arg(args, char *);
		return (write(1, tmp_s, ft_strlen(tmp_s)) + nbr);
	}
	if (*str == 'c' || *str == 'd' || *str == 'i')
		return (put_cdi(str, args) + nbr);
	if (*str == 'u' || *str == 'x' || *str == 'X')
		return (put_uxx(str, args) + nbr);
	if (*str == 'p')
	{
		tmp_ptr = va_arg(args, void *);
		if (tmp_ptr == NULL)
			return (write(1, "(nil)", 5) + nbr);
		write(1, "0x", 2);
		ft_putnbr_base((long long)tmp_ptr, "0123456789abcdef");
		return (ft_nbrlen((long long)tmp_ptr, 16) + 2 + nbr);
	}
	return(write(1, str, 1));
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
