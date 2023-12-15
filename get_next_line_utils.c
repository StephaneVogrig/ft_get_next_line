/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:51:06 by svogrig           #+#    #+#             */
/*   Updated: 2023/12/15 21:51:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_join(char *line, char *buffer, size_t len)
{
	char	*new_line;
	size_t	i;

	i = 0;
	if (line)
		while (line[i])
			i++;
	new_line = malloc(i + len + 1);
	if (!new_line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	new_line[i + len] = '\0';
	while (len--)
		new_line[i + len] = buffer[len];
	while (i--)
		new_line[i] = line[i];
	if (line)
		free(line);
	return (new_line);
}
