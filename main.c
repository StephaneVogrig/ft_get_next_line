/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:51:51 by svogrig           #+#    #+#             */
/*   Updated: 2023/12/17 11:22:55 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = 2048;
	//fd = open("empty.txt", O_RDONLY);
	//fd = 1024;
	//fd = open("text", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);

		printf("-------------\n");
		free(line);
		line = get_next_line(fd);
		i++;
	}
	
	//printf("\n");
	printf("%s", line);
	printf("\n");
	return (0);
	close(fd);

}

	//fd = -1;
	//fd = open("text", O_RDONLY);