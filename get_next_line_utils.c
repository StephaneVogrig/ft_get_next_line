/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:38:03 by stephane          #+#    #+#             */
/*   Updated: 2023/12/08 00:58:03 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	gnl_save(t_save **save, int *len, t_buffer *b, int start)
{
	//printf("start save\n");
	t_save	*new_save;
	int		size;
	
	if (!b->init)
		b->init = 1;
	if (b->size_used == -1 || start >= b->offset)
		return (1);
	new_save = malloc(sizeof(t_save));
	if(!new_save)
		return (0);
	size = b->offset - start;
	new_save->buffer = malloc(size);
	if (!new_save->buffer)
	{
		free(new_save);
		return (0);
	}
	new_save->size = size;
	gnl_copy(new_save->buffer, b->buffer + start, size);
	*len += size; 
	new_save->next = *save;
	*save = new_save;
	//printf("end save\n");
	return (1);
}

void	*gnl_free(t_save *save)
{
	//printf("start free\n");
	t_save	*temp;

	while (save)
	{
		temp = save->next;
		free(save->buffer);
		free(save);
		save = temp;
	}
	//printf("end free\n");
	return (NULL);
}

char	*gnl_line(t_save *save, int len, t_buffer *b, int start)
{
	//printf("start line\n");
	char	*line;
	int		size;
	t_save	*temp;

	size = b->offset - start;
	if(!len && !size)
		return (NULL);
	line = malloc(len + size + 1);
	//printf("malloc line:%p len:%i size:%i offset:%li start:%i\n", line, len, size, b->offset, start);
	if (!line)
		return (gnl_free(save));
	line[len + size] = '\0';
	gnl_copy(line + len, b->buffer + start, size);
	//printf("line:%s\n", line + len);
	start = len;
	temp = save;
	while(temp)
	{
		start = start - save->size;
		//printf("start:%i\n", start);
		//printf("line:%s\n", line);
		gnl_copy(line + start, temp->buffer, temp->size);
		temp = temp->next;
		//free(save);
		//save = temp;
	}
	gnl_free(save);
	//printf("end line\n");
	return (line);
}
