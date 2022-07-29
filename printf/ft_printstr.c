/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:44:37 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/12 13:09:29 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ftprintstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		ftprintstr("(null)");
		return (6);
	}
	else
	{
		while (*str)
		{
			i += write(1, str++, 1);
		}
		return (i);
	}
}
