
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# define FALSE 0
# define TRUE 1

char	*get_next_line(int fd);
void	gnl_copy(char *dest, char *src, size_t len);
char	*gnl_join(char *line, char *buffer, size_t len);
char	*gnl_free(char *line);

#endif
