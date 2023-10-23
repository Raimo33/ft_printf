/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:46:26 by craimond          #+#    #+#             */
/*   Updated: 2023/10/23 21:57:39 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	add_padding(char *str, unsigned int padding, char **tmp_str, struct flags *f)
{
	int		chars_written;
	char	*tmp_str1;
	char	*tmp_str2;

	chars_written = 0;
	if (*str == 'p' || *str == 'c' || *str == 's')
	{
		while (padding-- > 0)
			chars_written += (write(1, " ", 1));
	}
	else
	{	
		if (tmp_str != NULL && *tmp_str[0] == '-' && (*f).padding_char == '0')
		{
			chars_written += write (1, "-", 1);
			tmp_str1 = ft_strdup(*tmp_str);
			free(*tmp_str);
			tmp_str2 = ft_strtrim(tmp_str1, "-");
			*tmp_str = tmp_str2;
			free(tmp_str1);
		}
		else if ((*f).is_hash == 1 && (*str == 'x' || *str == 'X') && (*f).padding_char == '0')
		{
			if (*str == 'x')
				chars_written += write(1, "0x", 2);
			else if (*str == 'X')
				chars_written += write(1, "0X", 2);
			if (padding > 2)
				padding -= 2;
		}
		else if ((*f).is_plus == 1 && (*str == 'i' || *str == 'd') && (*f).padding_char == '0')
		{
			chars_written += write(1, "+", 1);
			if (padding > 1)
				padding -= 1;
		}
		while (padding-- > 0)
			chars_written += write(1, &(*f).padding_char, 1);
	}
	return (chars_written);
}
