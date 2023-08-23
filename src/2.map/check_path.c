/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:13:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 14:50:44 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: Flood fill
 * -----------------
 * This is a function that will check if the map has a path from the player to
 * the exit. It will use the flood fill algorithm to check if the map has a path
 * from the player to the exit. In my case, flood fill is a function that calls
 * the find_start_position function, the visited_matriz function, the fill and
 * the check_path function.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: This is a void function.
 *
 */

void	flood_fill(t_map *map)
{
	find_start_position(map, &map->pos_x, &map->pos_y);
	map->c_count = 0;
	map->visited = visited_matriz(map->rows, map->columns);
	fill(map, map->pos_x, map->pos_y);
	check_path(map);
}

/**
 * Function: Find start position
 * -----------------
 * This is a function that will find the start position of the player.
 * It will find the start position of the player, by searching for the 'P'
 * character in the map and saving the position in the pos_x and pos_y variables.
 * If the map doesn't have a 'P' character, the program will exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 * @param: *pos_x - Pointer to the x position of the player.
 * @param: *pos_y - Pointer to the y position of the player.
 *
 * @return: This is a void function.
 *
 */

void	find_start_position(t_map *map, int *pos_x, int *pos_y)
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
				*pos_x = col;
				*pos_y = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

/**
 * Function: Visited matriz
 * -----------------
 * This is a function that will create a visited matriz. It will create a visited
 * matriz, that will be used by the flood fill algorithm to check if the map has
 * a path from the player to the exit.
 * 
 * @param: rows - The number of rows in the map.
 * @param: columns - The number of columns in the map.
 *
 * @return: This function will return a double pointer to the visited matriz. 
 *
 */

int	**visited_matriz(int rows, int columns)
{
	int	**visited;
	int	row;
	int	col;

	row = 0;
	visited = (int **)malloc(sizeof(int *) * rows);
	if (!visited)
		return (NULL);
	while (row < rows)
	{
		visited[row] = (int *)malloc(sizeof(int) * columns);
		if (!visited[row])
			return (NULL);
		col = 0;
		while (col < columns)
		{
			visited[row][col] = 0;
			col++;
		}
		row++;
	}
	return (visited);
}

/**
 * Function: Fill
 * -----------------
 * This is a function that will fill the visited matriz. It will fill the visited
 * matriz, that will be used by the flood fill algorithm to check if the map has
 * 
 * @param: rows - The number of rows in the map.
 * @param: columns - The number of columns in the map.
 *
 * @return: This function will return a double pointer to the visited matriz. 
 *
 */

void	fill(t_map *map, int row, int col)
{
	if (row < 0 || row >= map->rows || col < 0 || col >= map->columns
		|| map->visited[row][col] == '#' || map->matriz[row][col] == '1'
		|| map->matriz[row][col] == 'X')
		return ;
	map->visited[row][col] = '#';
	fill(map, row + 1, col);
	fill(map, row - 1, col);
	fill(map, row, col + 1);
	fill(map, row, col - 1);
}

/**
 * Function: Check path
 * -----------------
 * This is a function that will check if the map has a path from the player to
 * the exit. It will check if the map has a path from the player to the exit, by
 * checking if the visited matriz has a '#' character in the exit position. If
 * the visited matriz doesn't have a '#' character in the exit position, the
 * program will exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

void	check_path(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if ((map->matriz[row][col] == 'E' || map->matriz[row][col] == 'C')
				&& map->visited[row][col] == 0)
				cleanup_and_exit(map, 1);
			if (map->matriz[row][col] == 'C' && map->visited[row][col] == '#')
				map->c_count++;
			col++;
		}
		row++;
	}
	cleanup_and_exit(map, 0);
}
