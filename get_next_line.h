/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:50:59 by svogrig           #+#    #+#             */
/*   Updated: 2023/12/15 21:51:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# define FALSE 0
# define TRUE 1

typedef struct s_buffer{
	char		data[BUFFER_SIZE];
	ssize_t		i;
}	t_buffer;

char	*get_next_line(int fd);
char	*gnl_join(char *line, char *buffer, size_t len);

#endif
