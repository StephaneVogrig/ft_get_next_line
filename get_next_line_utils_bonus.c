/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:52:48 by stephane          #+#    #+#             */
/*   Updated: 2023/12/10 03:37:22 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line_bonus.h"

void	gnl_memcpy(char *dest, char *src, int n)
{
	while (n--)
		*dest++ = *src++;	
}

int	gnl_memchr(char *buffer, char c, int n)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (i < n && buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_free(t_gnl *save)
{
	t_gnl	*temp;

	if (!save)
		return (NULL);
	while (save)
	{
		temp = save->next;
		if (save->str)
			free(save->str);
		free(save);
		save = temp;
	}
	return (NULL);
}
