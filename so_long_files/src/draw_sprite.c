#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	draw_background(t_game *game, t_map *map);
void	draw_exit_enemy(t_game *game, t_map *map);
void	draw_wall(t_game *game, t_map *map);
void	draw_coins(t_game *game, t_map *map);
void	draw_mario(t_game *game, t_map *map);

void	draw_wall(t_game *game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == '1')
			{
				game->object[1].x = col * SPRITE_SIZE;
				game->object[1].y = row * SPRITE_SIZE;
				draw_sprite(game, game->sprites.wall, &game->object[1]);
			}
			col++;
		}
		row++;
	}
}

void	draw_coins(t_game *game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'C')
			{
				game->object[2].x = col * SPRITE_SIZE;
				game->object[2].y = row * SPRITE_SIZE;
				draw_sprite(game, game->sprites.coins[game->current_coins],	&game->object[2]);
			}
			col++;
		}
		row++;
	}
}

void	draw_exit_enemy(t_game *game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'E')
			{
				game->object[3].x = col * SPRITE_SIZE;
				game->object[3].y = row * SPRITE_SIZE;
				draw_sprite(game, game->sprites.exit, &game->object[3]);
			}
			else if (map->matriz[row][col] == 'X')
			{
				game->object[4].x = col * SPRITE_SIZE;
				game->object[4].y = row * SPRITE_SIZE;
				draw_sprite(game, game->sprites.enemy, &game->object[4]);
			}
			col++;
		}
		row++;
	}
}
