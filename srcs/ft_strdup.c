/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:12:17 by craimond          #+#    #+#             */
/*   Updated: 2023/07/30 17:12:19 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src);
int		get_size(char *src);
/*
int main(void)
{
	printf("%s\n", ft_strdup("stringaaaa "));
}*/

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*copiedstr;

	i = 0;
	size = get_size(src);
	copiedstr = (char *) malloc(size);
	if (sizeof(copiedstr) < sizeof(src))
		return (0);
	while (src[i])
	{
		copiedstr[i] = src[i];
		i++;
	}
	copiedstr[i] = '\0';
	return (copiedstr);
}

int	get_size(char *src)
{
	int	n;

	n = 0;
	while (*(src + n))
		n++;
	return (n);
}
