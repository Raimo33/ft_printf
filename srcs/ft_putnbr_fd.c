/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:32:27 by craimond          #+#    #+#             */
/*   Updated: 2023/10/18 09:43:12 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;
	char	c;

	n_long = n;
	if (n_long < 0)
	{
		n_long *= -1;
		write(fd, "-", 1);
	}
	if (n_long >= 10)
		ft_putnbr_fd(n_long / 10, fd);
	c = (n_long % 10) + 48;
	write(fd, &c, 1);
}
