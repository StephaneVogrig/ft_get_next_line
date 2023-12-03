#include "get_next_line.h"
#include <string.h>

char *join(char *line, char *buffer, size_t len)
{
	char	*new_line;
	size_t	i;

	i = 0;
	if (line)
		while (line[i])
			i++;
	new_line = malloc(i + len);
	if (!new_line)
		return (NULL);
	if (line)
		memcpy(new_line, line, i - 1);
	memcpy(new_line + i, buffer, len);
	new_line[i + len] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	offset = -1;
	static ssize_t	size_read;
	ssize_t			start;
	char			*line;

	if (fd < 0)
		return (NULL);

	if (offset == -1)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
			return (NULL);
		offset = 0;
	}

	line = NULL;
	while (size_read)
	{
		start = offset;
		while (offset < size_read)
		{
			if (buffer[offset++] == '\n')
				return (join(line, buffer + start, offset - start));
		}
		line = join (line, buffer + start, offset - start);
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
			return (NULL);
		offset = 0;
	}
	return (line);
}
