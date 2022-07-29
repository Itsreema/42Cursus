/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:29:22 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/01 16:53:27 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	min(size_t size1, size_t size2)
{
	if (size1 < size2)
		return (size1);
	else
		return (size2);
}	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		j;

	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		else
			sub[0] = '\0';
		return (sub);
	}
	len = min(len, ft_strlen(s) - start);
	sub = (char *)malloc(len + 1);
	if (!s || !sub)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
