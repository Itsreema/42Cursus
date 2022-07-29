/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:16:12 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/12 15:33:06 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

size_t	ftprintchar(char c);
size_t	ftprintstr(char *str);
size_t	ftprintnum(unsigned long long nb, unsigned int base, char c);
int		ft_printf(const char *fmt, ...);
size_t	checkfmt(const char f, va_list args);
size_t	num_signed(long long nbr);
#endif
