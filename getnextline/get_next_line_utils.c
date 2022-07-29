/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:58:46 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/28 12:43:33 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	min(int size1, int size2)
{
	if (size1 < size2)
		return (size1);
	else
		return (size2);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub;
	int		j;
	int		k;

	k = ft_strlen(s);
	if (start >= k)
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		else
			sub[0] = '\0';
		return (sub);
	}
	len = min(len, k - start);
	sub = (char *)malloc(len + 1);
	if (!s || !sub)
		return (NULL);
	j = 0;
	while (start < k && j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}
