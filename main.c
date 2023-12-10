#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	//printf("  start main\n");
	int	fd1;
//	int	fd2;
	int i = 0;
	char *line = NULL;

	//fd = -1;
/*	fd1 = open("text", O_RDONLY);
*/	fd1 = 1;
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
		i++;
	}
/*	printf("\n deuxieme round\n");
	fd2 = open("text2", O_RDONLY);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		i++;
	}
	close(fd1);
	close(fd2);
*/	//printf("  end main\n");
	return (0);
}
