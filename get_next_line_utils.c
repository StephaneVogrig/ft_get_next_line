/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:52:48 by stephane          #+#    #+#             */
/*   Updated: 2023/12/10 04:25:35 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

void	gnl_memcpy(char *dest, char *src, int n)
{
	while (n--)
		*dest++ = *src++;	
}

int		gnl_memchr(char *buffer, char c, int n)
{
	int	i;

	i = 0;
	while (i < n && buffer[i])
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}