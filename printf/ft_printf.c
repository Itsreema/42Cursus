/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 11:45:04 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/13 14:41:16 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_signed(long long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		count += ftprintchar('-');
		count += ftprintnum(-nbr, 10, 0);
	}
	else
		count += ftprintnum(nbr, 10, 0);
	return (count);
}

size_t	ft_printptr(void *ptr)
{
	size_t	count;

	count = 0;
	ftprintstr("0x");
	count += 2;
	count += ftprintnum((size_t)ptr, 16, 'a');
	return (count);
}

size_t	checkfmt(const char f, va_list args)
{
	size_t	count;

	count = 0;
	if (f == 'c')
		count += (ftprintchar(va_arg(args, int)));
	else if (f == 's')
		count += (ftprintstr(va_arg(args, char *)));
	else if (f == 'x')
		count += (ftprintnum(va_arg(args, unsigned int), 16, 'a'));
	else if (f == 'X')
		count += (ftprintnum(va_arg(args, unsigned int), 16, 'A'));
	else if (f == 'p')
		count += (ft_printptr(va_arg(args, void *)));
	else if (f == 'u')
		count += (ftprintnum(va_arg(args, unsigned int), 10, 0));
	else if (f == 'd' || f == 'i')
		count += (num_signed(va_arg(args, int)));
	else if (f == '%')
				count += (ftprintchar(f));
	else
		count += (ftprintchar(f));
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, fmt);
	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (fmt[++i])
				count += checkfmt(fmt[i], args);
			else
				break ;
		}
		else
			count += ftprintchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (count);
}
