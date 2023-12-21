#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void 	print_all(char *path)
{
	char *line = NULL;
	int	fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf(">%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int main(void)
{
	printf("buffer size = %i\n", BUFFER_SIZE);
	printf("-----------------------------------------\n");
	printf("test 1 fd -1, expected null :\n>%s\n", get_next_line(-1));
	printf("-----------------------------------------\n");
	printf("test 2 empty file :\n");
	print_all("fichiers test/empty");
	printf("\n-----------------------------------------\n");
	printf("test 3 3lines :\n");
	print_all("fichiers test/3lines");
	printf("\n-----------------------------------------\n");
	printf("test 4 3lines_empty :\n");
	print_all("fichiers test/3lines_empty");
	printf("\n-----------------------------------------\n");
	//fd = -1;
/*	fd1 = open("text", O_RDONLY);
*/	
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
