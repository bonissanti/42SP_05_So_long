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
// #include "../../include/so_long.h"
#include "../../../my_libft/src/ft_strlen.c"
#include <stdio.h>

//Algorithm 'flood fill' to check if the 'P' is able to reach the 'E' in the map

typedef struct s_sprites
{
	void	*mario_l;
	void	*mario_r;
	void	*mario_u;
	void	*mario_d;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*victory;
}			t_sprites;

typedef struct s_player
{
	int x;
	int y;
	int direction_x;
	int direction_y;
	t_sprites sprites;
	int jumping;
	int on_ground;
}		t_player;

typedef enum e_game_state
{
	PLAYING,
	VICTORY,
	DEFEAT
}			t_game_state;


typedef struct s_map
{
	unsigned int	moves;
	char			**matriz;
    char			*file;
	int				rows;
	int				columns;
	int				player;
	int				collectible;
	int				c_count;
	int				exit;
	int				empty;
	int				wall;
}					t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_player	player;
	t_game_state state;
}				t_game;

void find_start_position(t_map *map, int *player_x, int *player_y);
void count_collectibles(t_map *map);
int flood_fill(t_game *game, int x, int y, char target, char replacement, int *count, int **visited);

void count_collectibles(t_map *map)
{
	int row;
	int col;

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

int flood_fill(t_game *game, int x, int y, char target, char replacement, int *count, int **visited)
{
	char original;
	int result;
	
	if (x < 0 || x >= game->map.rows || y < 0 || y >= game->map.columns)
		return (0);

	if (visited[x][y])
		return (0);
	
	visited[x][y] = 1;

	if (game->map.matriz[x][y] == 'E')
	{
		if (*count < game->map.collectible)
			return (0);
		else
			return (1);
	}

	original = game->map.matriz[x][y];

	if (original == 'C')
		*count += 1;
	
	if (original == '1' || original == 'E' || original == 'X')
		return (0);

	game->map.matriz[x][y] = replacement;

	result = flood_fill(game, x + 1, y, target, replacement, count, visited) ||
			 flood_fill(game, x, y + 1, target, replacement, count, visited) ||
			 flood_fill(game, x - 1, y, target, replacement, count, visited) ||
			 flood_fill(game, x, y - 1, target, replacement, count, visited);


	game->map.matriz[x][y] = original;
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



char **copy_matriz(char **original, int rows, int columns)
{
	char **copy;
	int x;
	int y;

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

void print_result(int result)
{
	if (result)
		printf("True: P can reach E and collect all C\n");
	else
		printf("False: P can't reach E or didn't collect all C\n");
}

void print_map(t_game game)
{
	int row;
	int col;

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

int **visited_matriz(int rows, int columns)
{
	int **visited;
	int x;
	int y;

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


int main(void)
{
	t_game game;

	char *zone[] = {
			"11111111111111111111",
			"1000C000000000000001",
			"10000000000000000001",
			"100E00C0000000000001",
			"10000000000000000001",
			"11111111111011111111",
			"10000000000000000001",
			"100000000C00000P0001",
			"10000000000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"11111111111111111111",
			NULL
	};


	game.map.rows = 0;

	while (zone[game.map.rows])
		game.map.rows++;

	game.map.columns = ft_strlen(zone[0]);
	game.map.matriz = copy_matriz(zone, game.map.rows, game.map.columns);
		
	find_start_position(&game.map, &game.player.x, &game.player.y);

	if (game.player.x == -1 || game.player.y == -1)
	{
		printf("Error\nMap must have one player\n");
		return (0);
	}

	count_collectibles(&game.map);
	game.map.c_count = 0;
	int **visited = visited_matriz(game.map.rows, game.map.columns);
	int result = flood_fill(&game, game.player.x, game.player.y, 'E', 'X', &game.map.c_count, visited);
	print_map(game);


	while (game.map.rows--)
		free(game.map.matriz[game.map.rows]);
	free(game.map.matriz);

	print_result(result);
}
