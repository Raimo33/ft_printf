/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:46:26 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 17:37:51 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	add_padding(char *str, unsigned int padding, unsigned char padding_char, char **tmp_str)
{
	int		chars_written;
	char 	*tmp_str1;
	char	*tmp_str2;

	chars_written = 0;
	if (*str == 'p' || *str == 'c' || *str == 's')
	{
		while (padding-- > 0)
			chars_written += (write(1, " ", 1));
	}
	else
	{
		if (*tmp_str[0] == '-')
		{
			chars_written += write (1, "-", 1);
			tmp_str1 = ft_strdup(*tmp_str);
			free(*tmp_str);
			tmp_str2 = ft_strtrim(tmp_str1, "-");
			*tmp_str = tmp_str2;
			free(tmp_str1);
		}
		while (padding-- > 0)
			chars_written += write(1, &padding_char, 1);
	}
	return (chars_written);
}
