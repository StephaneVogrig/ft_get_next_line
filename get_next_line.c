ii#include "get_next_line.h"

char	*get_next_line(int fd)
{

//	si buffer vide 
//		remplir buffer
//	chercher endline dans buffer a partir de precedente position
//	si endline pas trouve et pas fin de fichier
//		sauvegarder buffer
//		remplir buffer
//		recommencer chercher endline dans buffer
//	si endline pas trouve et fin de fichier dans buffer
//		construire ligne jusqu'a fin de fichier
//		effacer buffers sauvegarde
//		detruire buffer
//	si endline trouve
//		construire ligne jusqu'a endline trouve
//		effacer buffers sauvegarde
//		memoriser buffer actuel et position endline trouve
// renvoyer endline
	char		*line;
	int			len_line;
	static char	*buffer;
	ssize_t		size_read;
	char		*endl_found;

	line = NULL;
	len_line = 0;
	endl_found = NULL;
	size_read = 0;

	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}

	static int offset;

	while (endl_found == NULL)
	{	
		endl_found = memchr(buffer + offset, '\n', size_read - offset);
		if (!endl_found)
		{
			if (size_read < BUFFER_SIZE);
			{
				endl_found = buffer + size_read;
				offset = 0;
				break;
			}
			new_size_read = read(fd, buffer, BUFFER_SIZE);
			if (new_size_read == -1)
				return (NULL);
			if (new_size_read == 0)
				endl_found = 
		}
	}

	return (line);
}
