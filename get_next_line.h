/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:08:46 by stephane          #+#    #+#             */
/*   Updated: 2023/12/10 04:18:07 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# ifndef MAX_FD
#  define MAX_FD 1023
# endif

typedef struct s_gnl {
	char			*str;
	int				len;
	struct s_gnl	*next;
} t_gnl;

char *get_next_line(int fd);
void	gnl_memcpy(char *dest, char *src, int n);
int		gnl_memchr(char *buffer, char c, int n);

#endif