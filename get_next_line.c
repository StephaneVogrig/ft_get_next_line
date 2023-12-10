/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:34:58 by stephane          #+#    #+#             */
/*   Updated: 2023/12/08 00:25:55 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buffer	b;
	t_save			*save;
	ssize_t			start;
	int				len;

	if (fd < 0 || fd > 1024)
		return (NULL);
	save = NULL;
	len = 0;
	if (!b.init)
		b.size_used = -1;
	while (b.size_used)
	{
		start = b.offset;
		while (b.offset < b.size_used)
			if (b.buffer[b.offset++] == '\n')
				return (gnl_line(save, len, &b, start));
		if (!gnl_save(&save, &len, &b, start))
			return (gnl_free(save));
		b.size_used = read(fd, b.buffer, BUFFER_SIZE);
		if (b.size_used == -1)
			return(gnl_free(save)) ;
		b.offset = 0;
	}
	return (gnl_line(save, len, &b, 0));
}
