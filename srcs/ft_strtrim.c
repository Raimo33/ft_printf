/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:57:33 by craimond          #+#    #+#             */
/*   Updated: 2023/10/21 17:21:02 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_cinstr(const char *str, const char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*newstr;
	size_t	i;

	i = 0;
	while (*s1 != '\0' && ft_cinstr(set, *s1))
		s1++;
	i = f_strlen((char *)s1);
	while (i > 0 && ft_cinstr(set, s1[i - 1]))
		i--;
	newstr = malloc(sizeof(char) * (i + 1));
	if (newstr == NULL)
		return (NULL);
	newstr[i] = '\0';
	while (i > 0)
	{
		newstr[i - 1] = s1[i - 1];
		i--;
	}
	return (newstr);
}

static int	ft_cinstr(const char *str, const char c)
{
	while (*str != '\0')
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}
