/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputlen_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:20:08 by craimond          #+#    #+#             */
/*   Updated: 2023/10/19 23:32:32 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	outputlen_s(va_list *args, void *tmp)
{
	char	*str;

	tmp = (void *)va_arg(*args, char *);
	str = ft_strdup((char *)tmp);
	if (str == NULL)
		return (6);
	return (ft_strlen(str));
}
