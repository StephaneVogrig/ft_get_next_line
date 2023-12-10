
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FALSE 0
# define TRUE 1

#include <stdio.h>  //*************************************

typedef struct s_save{
	char 	*buffer;
	int		size;
	struct s_save	*next;
}	t_save;

typedef struct s_buffer{
	char	buffer[BUFFER_SIZE];
	char	init;
	ssize_t	offset;
	ssize_t	size_used;
}	t_buffer;

char	*get_next_line(int fd);
void	gnl_copy(char *dest, char *src, size_t len);

int		gnl_save(t_save **save, int *len, t_buffer *b, int start);
void	*gnl_free(t_save *line);

char	*gnl_line(t_save *save, int len, t_buffer *b, int start);

#endif
