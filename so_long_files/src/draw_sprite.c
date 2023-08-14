#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	draw_background(t_game *game, t_map *map);
void	draw_exit(t_game *game, t_map *map);
void	draw_wall(t_game *game, t_map *map);
void	draw_coins(t_game *game, t_map *map);
void	draw_mario(t_game *game, t_map *map);

void	draw_background(t_game *game, t_map *map)
{
	mlx_put_image_to_window(game->mlx, game->window,
			game->player.sprites.bg[game->current_bg], 0, 0);
}

void	draw_mario(t_game *game, t_map *map)
{
	int	row;
	int	col;
    void *sprite;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'P')
                set_mario_sprite(game, game->player.direction_x, game->player.direction_y);
			col++;
		}
		row++;
	}
}

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
				draw_sprite(game, game->player.sprites.wall, col * SPRITE_SIZE,
                        row * SPRITE_SIZE);
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
				draw_sprite(game, game->player.sprites.coins[game->current_coins],
                        col * SPRITE_SIZE, row * SPRITE_SIZE);
			col++;
		}
		row++;
	}
}

void	draw_exit(t_game *game, t_map *map)
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
				draw_sprite(game, game->player.sprites.exit, col * SPRITE_SIZE,
                        row * SPRITE_SIZE);
			col++;
		}
		row++;
	}
}
