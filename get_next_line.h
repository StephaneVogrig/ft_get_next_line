
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# define FALSE 0
# define TRUE 1

char	*get_next_line(int fd);

#endif
