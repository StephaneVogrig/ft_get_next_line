#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int	fd;
	int i = 0;
	char *line = NULL;

	//fd = -1;
	fd = open("text", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}	
	return (0);
}
