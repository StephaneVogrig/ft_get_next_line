#include "get_next_line.h"

void	gnl_copy(char *dest, char *src, size_t len)
{
	while (len)
	{
		*dest = *src;
		dest++;
		src++;
		len--;
	}
}

char	*gnl_join(char *line, char *buffer, size_t len)
{
	char	*new_line;
	size_t	i;

	i = 0;
	if (line)
		while (line[i])
			i++;
	new_line = malloc(i + len + 1);
	if (!new_line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (line)
	{
		gnl_copy(new_line, line, i);
		free(line);
	}
	gnl_copy(new_line + i, buffer, len);
	new_line[i + len] = '\0';
	return (new_line);
}
