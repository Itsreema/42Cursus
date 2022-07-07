/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:41:02 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/05 12:02:00 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*d;

	i = 0;
	if (!s)
		return (NULL);
	d = (char *) malloc (sizeof(char) * (ft_strlen(s)) + 1);
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = f (i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
