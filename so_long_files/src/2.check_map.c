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

void	get_map(t_map *map) //Function ok
{
	int fd;
	char *line;
	int i;
	
	if (!check_file(map->file))
	{
		printf("Error\nFile must be .ber\n");
		exit(1);
	}
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

//#################################### BASIC CHECKS ####################################

void call_checks(t_map *map)
{
	get_map(map);
	check_size(map);
	
	if (!check_wall(map))
	{
		printf("Error\nMap must be surrounded by walls\n");
		exit(1);
	}
	valid_char(map);
	
	count_coinss(map);
	if (map->coins == 0)
	{
		printf("Error\nMap must have at least one coins\n");
		exit(1);
	}
}

void check_path(t_map *map)
{
	find_start_position(map, &map->position_x, &map->position_y);
	if (map->position_x == -1 || map->position_y == -1)
	{
		printf("Error\nMap must have one player\n");
		exit(1);
	}

	map->c_count = 0;
	map->visited = visited_matriz(map->rows, map->columns);

	if (!flood_fill(map, map->position_x, map->position_y))
	{
		printf("Error\nMap must have a path from P to C and E\n");
		exit(1);
	}
	free_matriz(map->visited, map->rows);
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
		{
			printf("Error\nMap must be rectangular\n");
			exit(1);
		}
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
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

void	count_coinss(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	map->coins = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'C')
				map->coins++;
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
			{
				printf("Error\nMap must have valid characters\n");
				exit(1);
			}
			col++;
		}
		row++;
	}
	return (1);
}


int	flood_fill(t_map *map, int x, int y)
{
	char original;
	int result;

	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return (0);

	if (map->visited[x][y])
		return (0);

	map->visited[x][y] = 1;
	if (map->matriz[x][y] == 'E')
	{
		if (map->c_count == map->coins)
			return (1);
		else
			return (0);
	}
	original = map->matriz[x][y];
	if (original == 'C')
		map->c_count += 1;
	if (original == '1' || original == 'E' || original == 'X')
		return (0);
	map->matriz[x][y] = 'X';
	result = flood_fill(map, x + 1, y) ||
		flood_fill(map, x, y + 1) ||
		flood_fill(map, x - 1, y) ||
		flood_fill(map, x, y - 1);
	map->matriz[x][y] = original;
	return (result);
	
	
}

void	find_start_position(t_map *map, int *position_x, int *position_y)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'P')
			{
				*position_x = row;
				*position_y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

char	**copy_matriz(char **original, int rows, int columns)
{
	char	**copy;
	int		x;
	int		y;

	x = 0;
	copy = (char **)malloc(sizeof(char *) * rows);
	if (!copy)
		return (NULL);
	while (x < rows)
	{
		copy[x] = (char *)malloc(sizeof(char) * columns);
		if (!copy[x])
			return (NULL);
		y = 0;
		while (y < columns)
		{
			copy[x][y] = original[x][y];
			y++;
		}
		x++;
	}
	return (copy);
}

int	**visited_matriz(int rows, int columns)
{
	int	**visited;
	int	x;
	int	y;

	x = 0;
	visited = (int **)malloc(sizeof(int *) * rows);
	if (!visited)
		return (NULL);
	while (x < rows)
	{
		visited[x] = (int *)malloc(sizeof(int) * columns);
		if (!visited[x])
			return (NULL);
		y = 0;
		while (y < columns)
		{
			visited[x][y] = 0;
			y++;
		}
		x++;
	}
	return (visited);
}