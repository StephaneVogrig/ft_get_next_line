#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	offset = 0;
	static ssize_t	size_read = -1;
	ssize_t			start;
	char			*line;

	if (fd < 0)
		return (NULL);
	line = NULL;
	while (size_read)
	{
		start = offset;
		while (offset < size_read)
			if (buffer[offset++] == '\n')
				return (gnl_join(line, buffer + start, offset - start));
		if (size_read > -1 && start < offset)
			line = gnl_join (line, buffer + start, offset - start);
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
			return (gnl_free(line));
		offset = 0;
	}
	return (line);
}
