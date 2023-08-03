/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:21:26 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/03 18:13:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../../my_libft/src/ft_strlen.c"
#include "../../my_libft/src/get_next_line.c"
#include "../../my_libft/src/get_next_line_utils.c"
#include "../include/so_long.h"

//#################################### GET MAP ####################################



//#################################### CHECK PATH ####################################

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
		if (map->c_count == map->collectible)
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
		// printf("\n");
		row++;
	}
}

// int	main(void)
// {
// 	t_game	game;
// 	t_map	*map;
// 	int		result;

// 	map = &game.map;
// 	map->file = "../maps/map-test.ber";
// 	get_map(map);
// 	// map->matriz = copy_matriz(map->matriz, map->rows, map->columns);
// 	if (!check_size(map))
// 	{
// 		printf("Error\nMap must be rectangular\n");
// 		return (0);
// 	}
// 	if (!check_wall(map))
// 	{
// 		printf("Error\nMap must be surrounded by walls\n");
// 		return (0);
// 	}
// 	if (!valid_char(map))
// 	{
// 		printf("Error\nMap must have valid characters\n");
// 		return (0);
// 	}
// 	find_start_position(map, &game.player.x, &game.player.y);
// 	count_collectibles(map);
// 	map->c_count = 0;
// 	map->visited = visited_matriz(map->rows, map->columns);
// 	result = flood_fill(map, game.player.x, game.player.y);
// 	if (result)
// 		printf("True: P can reach E and collect all C\n");
// 	else
// 		printf("False: P can't reach E or didn't collect all C\n");
// 	print_map(game);
// }

// int main(void)
// {
// 	t_game game;

// 	game.map.file = "multi-players.ber";

// 	get_map(&game.map);

// 	game.map.matriz = copy_matriz(game.map.matriz, game.map.rows,
			// game.map.columns);

// 	find_start_position(&game.map, &game.player.x, &game.player.y);

// 	if (game.player.x == -1 || game.player.y == -1)
// 	{
// 		printf("Error\nMap must have one player\n");
// 		return (0);
// 	}

// 	count_collectibles(&game.map);
// 	game.map.c_count = 0;
// 	int **visited = visited_matriz(game.map.rows, game.map.columns);
// 	int result = flood_fill(&game, game.player.x, game.player.y, 'E', 'X',
			// &game.map.c_count, visited);
// 	print_map(game);

// 	while (game.map.rows--)
// 		free(game.map.matriz[game.map.rows]);
// 	free(game.map.matriz);

// 	print_result(result);
// }

// int	flood_fill(t_game *game, int x, int y, char target, char replacement, int *count, int **visited)
// {
// 	char	original;
// 	int		result;

// 	if (x < 0 || x >= game->map.rows || y < 0 || y >= game->map.columns)
// 		return (0);
// 	if (visited[x][y])
// 		return (0);
// 	visited[x][y] = 1;
// 	if (game->map.matriz[x][y] == 'E')
// 	{
// 		if (*count < game->map.collectible)
// 			return (0);
// 		else
// 			return (1);
// 	}
// 	original = game->map.matriz[x][y];
// 	if (original == 'C')
// 		*count += 1;
// 	if (original == '1' || original == 'E' || original == 'X')
// 		return (0);
// 	game->map.matriz[x][y] = replacement;
// 	result = flood_fill(game, x + 1, y, target, replacement, count, visited) ||
// 		flood_fill(game, x, y + 1, target, replacement, count, visited) ||
// 		flood_fill(game, x - 1, y, target, replacement, count, visited) ||
// 		flood_fill(game, x, y - 1, target, replacement, count, visited);
// 	game->map.matriz[x][y] = original;
// 	return (result);
// }