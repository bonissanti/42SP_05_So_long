#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	mlx_hooks(t_game *game);
int	    animation_loop(t_game *game);

int	animation_loop(t_game *game)
{
	if (game->frame_counter % 200 == 0)
		game->current_coins = (game->current_coins + 1) % 3;
	game->frame_counter++;
	if (game->frame_bg % 150 == 0)
		game->current_bg = (game->current_bg + 1) % 4;
	game->frame_bg++;
	if (game->frame_mario_l % 200 == 0)
		game->current_mario_l = (game->current_mario_l + 1) % 3;
	game->frame_mario_l++;
	if (game->frame_mario_r % 200 == 0)
		game->current_mario_r = (game->current_mario_r + 1) % 3;
	game->frame_mario_r++;
	if (game->frame_mario_u % 200 == 0)
		game->current_mario_u = (game->current_mario_u + 1) % 3;
	game->frame_mario_u++;
	if (game->frame_mario_d % 200 == 0)
		game->current_mario_d = (game->current_mario_d + 1) % 3;
	game->frame_mario_d++;
	draw_game(game, &game->map);
	return (0);
}

void	mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &animation_loop, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}