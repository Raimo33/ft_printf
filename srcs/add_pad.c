/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:15:23 by craimond          #+#    #+#             */
/*   Updated: 2023/10/26 11:16:31 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	zero_pad_minus(char **tmp_str, char **tmp_str1, char **tmp_str2);
static int	zero_pad_hash(ui *pad, char *str);
static int	zero_pad_plus(ui *pad);

int	add_pad(char *str, ui pad, char **tmp_str, t_flags *f)
{
	int		chars_written;
	char	*tmp_str1;
	char	*tmp_str2;

	chars_written = 0;
	if (*str == 'p' || *str == 'c' || *str == 's')
	{
		while (pad-- > 0)
			chars_written += (write(1, " ", 1));
	}
	else
	{
		if (tmp_str != NULL && *tmp_str[0] == '-' && (*f).pad_ch == '0')
			chars_written += zero_pad_minus(tmp_str, &tmp_str1, &tmp_str2);
		else if ((*f).is_hash == 1 && (*str == 'x' || *str == 'X')
			&& (*f).pad_ch == '0')
			chars_written += zero_pad_hash(&pad, str);
		else if ((*f).is_plus == 1 && (*str == 'i' || *str == 'd')
			&& (*f).pad_ch == '0')
			chars_written += zero_pad_plus(&pad);
		while (pad-- > 0)
			chars_written += write(1, &(*f).pad_ch, 1);
	}
	return (chars_written);
}

static int	zero_pad_minus(char **tmp_str, char **tmp_str1, char **tmp_str2)
{
	*tmp_str1 = ft_strdup(*tmp_str);
	free(*tmp_str);
	*tmp_str2 = ft_strtrim(*tmp_str1, "-");
	*tmp_str = *tmp_str2;
	free(*tmp_str1);
	return (write (1, "-", 1));
}

static int	zero_pad_hash(ui *pad, char *str)
{
	if (*pad > 2)
		*pad -= 2;
	if (*str == 'x')
		return (write(1, "0x", 2));
	else if (*str == 'X')
		return (write(1, "0X", 2));
	return (0);
}

static int	zero_pad_plus(ui *pad)
{
	if (*pad > 1)
		*pad -= 1;
	return (write(1, "+", 1));
}
