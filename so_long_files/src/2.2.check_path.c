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
#include "../include/so_long.h"



// void check_path(t_map *map)
// {
// 	find_start_position(map, &map->position_x, &map->position_y);
// 	if (map->position_x == -1 || map->position_y == -1)
// 	{
// 		printf("Error\nMap must have one player\n");
// 		exit(1);
// 	}

// 	map->c_count = 0;
// 	map->visited = visited_matriz(map->rows, map->columns);

	
// 	flood_fill(map);
// 	if (map->c_count != map->coins)
// 	{
// 		printf("Error\nMap must have a path from P to all C\n");
// 		exit(1);
// 	}

// 	if (!is_exit_reachable(map, map->position_x, map->position_y))
// 	{
// 		printf("Error\nMap must have a path from P to E\n");
// 		exit(1);
// 	}
// 	free_matriz(map->visited, map->rows);
// }


void flood_fill(t_map *map)
{
	find_start_position(map, &map->position_x, &map->position_y);
	
	if (map->position_x == -1 || map->position_y == -1)
	{
		printf("Error\nMap must have one player\n");
		exit(1);
	}
	map->visited = visited_matriz(map->rows, map->columns);
	fill(map, map->position_x, map->position_y);
	check_path(map);
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
				*position_x = col;
				*position_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
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

void fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns || (map->visited[x][y] != 0 && map->visited[x][y] != 'P' && map->visited[x][y] != 'E' && map->visited[x][y] != 'C'))
		return ;
	
	map->visited[x][y] = 1;

	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}


int check_path(t_map *map)
{
	int row;
	int col;

	row = 0;
	map->c_count = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if ((map->matriz[row][col] == 'E' || map->matriz[row][col] == 'C') && map->visited[row][col] == 0)
			{
				printf("Error\nMap must have a path from P to all C and E\n");
				free_matriz(map->visited, map->rows);
				exit (1);
			}
			if (map->matriz[row][col] == 'C' && map->visited[row][col] == 1)
				map->c_count++;
			col++;
		}
		row++;
	}
	free_matriz(map->visited, map->rows);
	return (1);
}


void print_map(t_map map)
{
	int row;
	int col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.columns)
		{
			printf("%c", map.matriz[row][col]);
			col++;
		}
		row++;
	}
}