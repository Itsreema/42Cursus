/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:27 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/12 15:30:17 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ftprintnum(unsigned long long nb, unsigned int base, char c)
{
	size_t	count;

	count = 0;
	if (nb < 10)
	{
	count += ftprintchar(nb + 48);
		return (count);
	}
	else if (nb >= 10 && nb < base)
	{
		count += ftprintchar(c + (nb - 10));
		return (count);
	}
	else
	{
	count += ftprintnum(nb / base, base, c);
	count += ftprintnum(nb % base, base, c);
	}
	return (count);
}
