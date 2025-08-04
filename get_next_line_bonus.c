/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakahuate <kakahuate@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:55:24 by kakahuate         #+#    #+#             */
/*   Updated: 2025/06/30 12:20:46 by kakahuate        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save_remaining(char *rest)
{
	char		*remaining;
	const char	*newline_ptr;

	newline_ptr = ft_strchr(rest, '\n');
	if (!newline_ptr)
	{
		free(rest);
		return (NULL);
	}
	remaining = ft_strdup(newline_ptr + 1);
	free(rest);
	return (remaining);
}

char	*ft_extract_newline(char *rest)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = rest[j];
		j++;
	}
	if (rest[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_read_until_newline(int fd, char *rest)
{
	char		*buffer;
	ssize_t		read_bytes;
	char		*new_rest;

	read_bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(rest, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		new_rest = ft_strjoin(rest, buffer);
		free(rest);
		rest = new_rest;
	}
	free(buffer);
	return (rest);
}

char	*get_next_line_bonus(int fd)
{
	static char	*rest[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (rest[fd] == NULL)
	{
		rest[fd] = malloc(1);
		if (!rest[fd])
			return (NULL);
		rest[fd][0] = '\0';
	}
	rest[fd] = ft_read_until_newline(fd, rest[fd]);
	if (!rest[fd] || rest[fd][0] == '\0')
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	line = ft_extract_newline(rest[fd]);
	rest[fd] = ft_save_remaining(rest[fd]);
	return (line);
}
