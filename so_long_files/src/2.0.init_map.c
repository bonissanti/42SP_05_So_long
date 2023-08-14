/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:13:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/10 18:20:39 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../../my_libft/src/ft_strlen.c"
#include "../../my_libft/src/ft_strncmp.c"
#include "../../my_libft/src/get_next_line.c"
#include "../../my_libft/src/get_next_line_utils.c"
#include "../include/so_long.h"

void	init_map(t_map *map);
int		count_lines(t_map *map);
void	get_map(t_map *map);

void	init_map(t_map *map)
{
	get_map(map);
	check_players(map);
	check_exit(map);
	check_size(map);
	if (!check_wall(map))
	{
		printf("Error\nMap must be surrounded by walls\n");
		exit(1);
	}
	valid_char(map);
	count_coins(map);
	if (map->coins == 0)
	{
		printf("Error\nMap must have at least one coins\n");
		exit(1);
	}
}

int	count_lines(t_map *map)
{
	int		fd;
	char	buffer[4096];
	int		bytes_read;
	int		line_count;
	int		i;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		exit(1);
	}
	line_count = 0;
	while ((bytes_read = read(fd, buffer, 4096)))
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i++] == '\n' || buffer[i] == '\0')
				line_count++;
		}
	}
	close(fd);
	return (line_count);
}

void	get_map(t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	check_file(map->file);
	map->rows = count_lines(map);
	map->matriz = malloc(sizeof(char *) * (map->rows));
	if (!map->matriz)
	{
		printf("Error allocating memory\n");
		exit(1);
	}
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		exit(1);
	}
	i = 0;
	while (i < map->rows)
		map->matriz[i++] = get_next_line(fd);
	map->columns = ft_strlen(map->matriz[0]);
	close(fd);
}

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	else if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		printf("Error\nFile must be .ber\n");
		exit(1);
	}
	return (1);
}
