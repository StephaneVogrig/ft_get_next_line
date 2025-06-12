/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:08:50 by stephane          #+#    #+#             */
/*   Updated: 2023/12/11 17:47:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_clean_buffer(char *buffer, int len_b)
{
	char	*buffd;
	int		len_to_copy;

	if (len_b == 0)
		return ;
	if (len_b < BUFFER_SIZE)
	{
		len_to_copy = BUFFER_SIZE - len_b;
		buffd = buffer + len_b;
		while (len_to_copy-- && *buffd)
			*buffer++ = *buffd++;
	}
	*buffer = '\0';
}

static char	*gnl_free(t_gnl *save)
{
	t_gnl	*temp;

	if (!save)
		return (NULL);
	while (save)
	{
		temp = save->next;
		if (save->str)
			free(save->str);
		free(save);
		save = temp;
	}
	return (NULL);
}

static char	*gnl_build_line(t_gnl *save, int len_s, char *buffer, int len_b)
{
	char	*line;
	t_gnl	*temp;
	int		i;

	if (!len_b && !len_s)
		return (NULL);
	i = len_s + len_b;
	line = malloc(i + 1);
	if (!line)
		return (gnl_free(save));
	line[i] = '\0';
	gnl_memcpy(line + len_s, buffer, len_b);
	while (save)
	{
		temp = save->next;
		len_s -= save->len;
		gnl_memcpy(line + len_s, save->str, save->len);
		free(save->str);
		free(save);
		save = temp;
	}
	gnl_clean_buffer(buffer, len_b);
	return (line);
}

static int	gnl_save(char *buffer, t_gnl **save, int *len_s)
{
	t_gnl	*new;
	int		len;

	if (!*buffer)
		return (1);
	new = malloc(sizeof(t_gnl));
	if (!new)
		return (0);
	new->next = *save;
	*save = new;
	len = 0;
	while (len < BUFFER_SIZE && buffer[len])
		len++;
	new->str = malloc(len);
	if (!new->str)
		return (0);
	new->len = len;
	*len_s += len;
	gnl_memcpy(new->str, buffer, len);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_gnl		*save;
	int			len_save;
	int			size_read;
	int			offset;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	save = NULL;
	len_save = 0;
	size_read = -1;
	while (size_read)
	{
		offset = gnl_memchr(buffer, '\n', BUFFER_SIZE);
		if (offset >= 0)
			return (gnl_build_line(save, len_save, buffer, offset + 1));
		if (!gnl_save(buffer, &save, &len_save))
			return (gnl_free(save));
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (0 <= size_read && size_read < BUFFER_SIZE)
			buffer[size_read] = '\0';
		if (size_read == -1)
			return (gnl_free(save));
	}
	return (gnl_build_line(save, len_save, buffer, 0));
}
