/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:35:38 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/02 17:00:06 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../../my_libft/src/ft_strlen.c"
#include "../../my_libft/src/get_next_line.c"
#include "../../my_libft/src/get_next_line_utils.c"
#include "../include/so_long.h"

void	find_start_position(t_map *map, int *player_x, int *player_y);
void	count_collectibles(t_map *map);

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

void flood_fill(t_map *map, int x, int y)
{
	char original;

	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
		return ;
	if (map->visited[x][y])
		return ;
	map->visited[x][y] = 1;
	if (map->matriz[x][y] == 'E')
	{
		if (map->c_count == map->collectible)
			return ;
		else
			return ;
	}
	original = map->matriz[x][y];
	if (original == 'C')
		map->c_count += 1;
	if (original == 'E' || original == '1' || original == 'X')
		return ;
	map->matriz[x][y] = map->replacement;
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	map->matriz[x][y] = original;
}


void	find_start_position(t_map *map, int *player_x, int *player_y)
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
				*player_x = row;
				*player_y = col;
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

void	print_result(int result)
{
	if (result)
		printf("True: P can reach E and collect all C\n");
	else
		printf("False: P can't reach E or didn't collect all C\n");
}

void	print_map(t_game game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game.map.rows)
	{
		col = 0;
		while (col < game.map.columns)
		{
			printf("%c", game.map.matriz[row][col]);
			col++;
		}
		printf("\n");
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

// int	main(void)
// {
// 	t_game	game;
// 	int		**visited;
// 	int		result;

// 	char *zone[] = {
// 		"11111111111111111111",
// 		"1000C000000000000001",
// 		"10000000000000000001",
// 		"100E00C0000000000001",
// 		"10000000000000000001",
// 		"11111111111011111111",
// 		"10000000000000000001",
// 		"100000000C00000P0001",
// 		"10000000000000000001",
// 		"10000000000000000001",
// 		"10000000000000000001",
// 		"11111111111111111111",
// 		NULL};
// 	game.map.rows = 0;
// 	while (zone[game.map.rows])
// 		game.map.rows++;
// 	game.map.columns = ft_strlen(zone[0]);
// 	game.map.matriz = copy_matriz(zone, game.map.rows, game.map.columns);
// 	find_start_position(&game.map, &game.player.x, &game.player.y);
// 	if (game.player.x == -1 || game.player.y == -1)
// 	{
// 		printf("Error\nMap must have one player\n");
// 		return (0);
// 	}
// 	count_collectibles(&game.map);
// 	game.map.c_count = 0;
// 	visited = visited_matriz(game.map.rows, game.map.columns);
// 	result = flood_fill
// 			&game.map.c_count, visited);
// 	print_map(game);
// 	while (game.map.rows--)
// 		free(game.map.matriz[game.map.rows]);
// 	free(game.map.matriz);
// 	print_result(result);
// }


//if (map->x < 0 || map->x >= map->rows || map->y < 0 || map->y >= map->col)