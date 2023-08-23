/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:51:00 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:54 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: get_lines
 * -----------------
 * Reads the map file and counts the number of lines in it.
 *
 * @param: map -  The map struct.
 *
 * @return: Returns the number of lines in the map file.
 *
 * Note: This function opens the file, reads the buffer and counts the number of
 * lines in it, and then closes the file. 
 */

int	get_lines(t_map *map)
{
	int		fd;
	char	buffer[4096];
	int		bytes_read;
	int		line_count;

	bytes_read = 0;
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	line_count = 0;
	bytes_read = read(fd, buffer, 4096);
	while (bytes_read > 0)
	{
		line_count += count_lines(buffer, bytes_read);
		bytes_read = read(fd, buffer, 4096);
	}
	close(fd);
	return (line_count);
}

/**
 * Function: count_lines
 * -----------------
 * Count the number of lines in the buffer.
 *
 * @param: buffer -  A pointer to the buffer that contains the file.
 * @param: bytes_read -  The number of bytes read from the file.
 *
 * @return: Returns the number of lines in the buffer.
 *
 * Note: This function r
 */

int	count_lines(char *buffer, int bytes_read)
{
	int	line_count;
	int	i;

	line_count = 0;
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			line_count++;
		i++;
	}
	return (line_count);
}
