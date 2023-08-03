/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:13:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/03 18:15:10 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../../my_libft/src/ft_strlen.c"
#include "../../my_libft/src/get_next_line.c"
#include "../../my_libft/src/get_next_line_utils.c"
#include "../include/so_long.h"

int	count_lines(t_map *map)
{
	int fd;
	char buffer[4096];
	int bytes_read;
	int line_count;
	int i;

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
			if (buffer[i] == '\n' || buffer[i] == '\0')
				line_count++;
			i++;
		}
	}
	close(fd);
	return (line_count);
}

void	get_map(t_map *map) //Function ok
{
	int fd;
	char *line;
	int i;

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
	{
		map->matriz[i] = get_next_line(fd);
		i++;
	}
	map->columns = ft_strlen(map->matriz[0]);
	close(fd);
}

//#################################### BASIC CHECKS ####################################

void call_checks(t_map *map)
{
	if (!check_size(map))
	{
		printf("Error\nMap must be rectangular\n");
		exit(1);
	}
	if (!check_wall(map))
	{
		printf("Error\nMap must be surrounded by walls\n");
		exit(1);
	}
	if (!valid_char(map))
	{
		printf("Error\nMap must have valid characters\n");
		exit(1);
	}
	count_collectibles(map);
	if (map->collectible == 0)
	{
		printf("Error\nMap must have at least one collectible\n");
		exit(1);
	}
}

int	check_size(t_map *map) // Function ok
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->matriz[row][col] != '\0')
			col++;
		if (col != map->columns)
			return (0);
		row++;
	}
	return (1);
}

int	check_wall(t_map *map) // Function ok
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == '\n')
			{
				col++;
				continue ;
			}
			if ((row == 0 || row == map->rows - 1 || col == 0
					|| col == map->columns - 1))
			{
				if (map->matriz[row][col] != '1')
				{
					printf("Last row: %d\n", map->rows - 1);
					return (0);
				}
			}
			col++;
		}
		row++;
	}
	return (1);
}

void	count_collectibles(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	map->collectible = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'C')
				map->collectible++;
			col++;
		}
		row++;
	}
}

int	valid_char(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] != '0' && map->matriz[row][col] != '1'
				&& map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E'
				&& map->matriz[row][col] != 'P'
				&& map->matriz[row][col] != '\n')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}