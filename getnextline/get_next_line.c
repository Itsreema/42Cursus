/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkumar <gkumar@student.42adel.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:56:20 by gkumar            #+#    #+#             */
/*   Updated: 2022/07/27 11:10:27 by gkumar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* this function takes a string, allocates sufficient memory to 
 * copy that string into, then copies the
 * string into the allocated memory space. 
 * It returns a pointer to the new string location. */

char	*ft_strdup(const char *src)
{
	int		len;
	int		x;
	char	*dest;

	len = 0;
	x = ft_strlen(src);
	dest = (char *)malloc(sizeof(src) * (x + 1));
	if (!dest)
		return (NULL);
	while (len < x)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
/*It searches through the  string to find newline
 * character or end of file. Null terminates
 * the string at that point and returns any
 * leftovers for next function call.*/

static char	*extract_newline(char *line)
{
	char	*leftover;
	int		i;

	leftover = NULL;
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
		return (leftover);
	if (line[i + 1])
	leftover = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	line[i + 1] = '\0';
	return (leftover);
}
/*It reads number of bytes according to BUFFER_SIZE
 * and stores them in a buffer string. It then checks
 * to see if a new line or the end of file are found in the
 * static string. If they are not, the buffer is appended
 * to the string and the read function is called again. */

static char	*find_newline(int fd, char *buffer, char *backup)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

/*It returns one line from a source determined by the fd.
 * if the fd is not valid, returns nothing. Since this
 * function uses a buffer of indeterminate size to take 
 * information in chunks, any leftover data must be stored
 * in the static char "backup". */

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup;

	if ((BUFFER_SIZE <= 0) || (fd < 0) || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	line = find_newline(fd, buffer, backup);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (line);
	backup = extract_newline(line);
	return (line);
}
