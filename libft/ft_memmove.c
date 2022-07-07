/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:01:02 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/01 10:46:51 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
/*int main () {
    char dst[] = "the dest";
    const char src[]  = "our src string";

    printf("Before memmove dest = %s, src = %s\n", dst, src);
    ft_memmove(dst, src, 9);
    printf("After memmove dest = %s, src = %s\n", dst, src);

    return(0);
 }*/
