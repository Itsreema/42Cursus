/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:22:04 by gkumar            #+#    #+#             */
/*   Updated: 2022/06/30 11:18:10 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (needle[j++] == haystack[i])
		{
			while (needle[j] && haystack[i + j] && needle[j] == haystack[i + j])
				j++;
			if (!needle[j] && (i + j) <= len)
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}
