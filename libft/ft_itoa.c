/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:49:42 by gkumar            #+#    #+#             */
/*   Updated: 2022/06/28 16:49:32 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(long int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int		num;
	int				sign;
	char			*result;
	unsigned int	digits;

	num = n;
	sign = 0;
	digits = countdigits(num);
	if (num < 0)
	{
		num *= -1;
		sign = -1;
	}
	result = ft_calloc((digits + 1), sizeof(char));
	if (!result)
		return (0);
	result[0] = '-';
	while (digits + sign)
	{
		result[digits - 1] = (num % 10 + '0');
		num /= 10;
		digits--;
	}
	return (result);
}
