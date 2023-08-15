#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void set_mario_sprite(t_game *game, int direction_x, int direction_y);
void draw_sprite(t_game *game, void *sprite, int x, int y);
void	draw_game(t_game *game, t_map *map);

void set_mario_sprite(t_game *game, int direction_x, int direction_y)
{
    void *sprite;

    if (game->player.direction_x < 0)
        sprite = game->sprites.mario_l[game->current_mario_l];
	else if (game->player.direction_x > 0)
        sprite = game->sprites.mario_r[game->current_mario_r];
	else if (game->player.direction_y < 0)
        sprite = game->sprites.mario_u[game->current_mario_u];
	else if (game->player.direction_y > 0)
        sprite = game->sprites.mario_d[game->current_mario_d];
	else
        sprite = game->sprites.mario_r[game->current_mario_r];
    draw_sprite(game, sprite, game->player.x, game->player.y);
}

void draw_sprite(t_game *game, void *sprite, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->window, sprite, x, y);
}

void	draw_game(t_game *game, t_map *map)
{
	mlx_clear_window(game->mlx, game->window);
	draw_background(game, map);
	draw_exit_enemy(game, map);
	draw_wall(game, map);
	draw_coins(game, map);
	draw_mario(game, map);
}