/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:51:00 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 10:51:01 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
