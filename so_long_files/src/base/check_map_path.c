/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:35:38 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/28 18:47:47 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"
#include "../../../my_libft/src/ft_strlen.c"

//Algorithm 'flood fill' to check if the 'P' is able to reach the 'E' in the map

void find_start_position(t_map *map, int *player_x, int *player_y);
void count_collectibles(t_map *map);
int flood_fill(t_game *game, int x, int y, char target, char replacement, int *count);



void count_collectibles(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->map_matriz[row][col] == 'C')
				map->collectible++;
			col++;
		}
		row++;
	}
}

int flood_fill(t_game *game, int x, int y, char target, char replacement, int *count)
{
	int result;
	
	if (x < 0 || x >= game->map.rows || y < 0 || y >= game->map.columns)
		return (0);

	if (game->map.map_matriz[x][y] == target)
	{
		if (*count < game->map.collectible)
			return (0);
		else
			return (1);
	}

	if (game->map.map_matriz[x][y] == 'C')
		*count += 1;
	
	if (game->map.map_matriz[x][y] != '0')
		return (0);

	game->map.map_matriz[x][y] = replacement;

	result = flood_fill(game, x + 1, y, target, replacement, count) ||
			 flood_fill(game, x - 1, y, target, replacement, count) ||
			 flood_fill(game, x, y + 1, target, replacement, count) ||
			 flood_fill(game, x, y - 1, target, replacement, count);
	
	game->map.map_matriz[x][y] = '0';

	if (game->map.map_matriz[x][y] == 'C')
		*count -= 1;
	
	return (result);
}

void find_start_position(t_map *map, int *player_x, int *player_y)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->map_matriz[row][col] == 'P')
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

void print_result(int result)
{
	if (result)
		printf("True: P can reach E and collect all C\n");
	else
		printf("False: P can't reach E or didn't collect all C\n");
}




int main(void)
{
	t_game game;

	char *zone[] = {
			"11111111111111111111",
			"1000C000000000000001",
			"10000000000000000001",
			"100E00C0000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"100000000C00000P0001",
			"10000000000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"11111111111111111111",
			NULL
	};

	game.map.map_matriz = zone;

	game.map.rows = 0;

	while (zone[game.map.rows])
		game.map.rows++;

	game.map.columns = ft_strlen(zone[0]);
	
		
	find_start_position(&game.map, &game.map.player_x, &game.map.player_y);

	if (game.map.player_x == -1 || game.map.player_y == -1)
	{
		printf("Error\nMap must have one player\n");
		return (0);
	}

	count_collectibles(&game.map);
	int result = flood_fill(&game, game.map.player_x, game.map.player_y, 'E', 'X', &game.map.c_count);

	print_result(result);
}

// int main(void)
// {
// 	char *zone[] = {
// 			"11111111111111111111",
// 			"100000000E0000000001",
// 			"100000000000000C0001",
// 			"10000000000000000001",
// 			"11111111011111111111",
// 			"100000C00000P0000001",
// 			"10000000000000000001",
// 			"10000000000000000001",
// 			"100000000C0000000001",
// 			"10000000000000000001",
// 			"10000000000000000001",
// 			"11111111111111111111",
// 			NULL
// 	};

// 	int rows = 12;
// 	int cols = 20;
// 	int count = 0;
// 	int total = 3;
// 	int result = flood_fill(zone, 5, 11, 'E', 'X', rows, cols, &count, total);

// 	if (result)
// 		printf("True: P can reach E and collect all C\n");
// 	else
// 		printf("False: P can't reach E or didn't collect all C\n");
// 	return (0);
// }