/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:50:56 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/29 12:03:59 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42000
# endif

char		*get_next_line(int fd);
int			min(int size1, int size2);
char		*ft_substr(char const *s, int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *c);
char		*ft_strdup(const char *src);

#endif
