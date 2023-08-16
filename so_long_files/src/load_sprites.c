#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	load_bg_sprites(t_game *game);
void	load_mario_sprites(t_game *game);
void	load_others_sprites(t_game *game);
void    load_error(t_game *game);

void	load_sprites(t_game *game, t_map *map)
{
	load_bg_sprites(game);
	load_mario_sprites(game);
	load_others_sprites(game);
	if (!game->sprites.bg[0] || !game->sprites.bg[1]
		|| !game->sprites.bg[2] || !game->sprites.bg[3]
		|| !game->sprites.mario_r[0] || !game->sprites.mario_r[1]
		|| !game->sprites.mario_r[2] || !game->sprites.mario_d[0]
		|| !game->sprites.mario_d[1] || !game->sprites.mario_d[2]
		|| !game->sprites.mario_l[0] || !game->sprites.mario_l[1]
		|| !game->sprites.mario_l[2] || !game->sprites.mario_u[0]
		|| !game->sprites.mario_u[1] || !game->sprites.mario_u[2]
		|| !game->sprites.wall || !game->sprites.coins[0]
		|| !game->sprites.coins[1] || !game->sprites.coins[2]
		|| !game->sprites.exit || !game->sprites.enemy)
	{
		load_error(game);
	}
	find_start_position(&game->map, &game->map.pos_x, &game->map.pos_y);
	game->object->x = game->map.pos_x * SPRITE_SIZE;
	game->object->y = game->map.pos_y * SPRITE_SIZE;
	draw_game(game, map);
}

void	load_bg_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.bg[0] = load_buffer(game->mlx, BG, &width, &height);
	game->sprites.bg[1] = load_buffer(game->mlx, BG2, &width, &height);
	game->sprites.bg[2] = load_buffer(game->mlx, BG3, &width, &height);
	game->sprites.bg[3] = load_buffer(game->mlx, BG4, &width, &height);
}

void	load_mario_sprites(t_game *game)
{
	game->sprites.mario_r[0] = load_buffer(game->mlx, MARIO_R1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_r[1] = load_buffer(game->mlx, MARIO_R2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_r[2] = load_buffer(game->mlx, MARIO_R3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[0] = load_buffer(game->mlx, MARIO_L1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[1] = load_buffer(game->mlx, MARIO_L2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[2] = load_buffer(game->mlx, MARIO_L3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[0] = load_buffer(game->mlx, MARIO_U1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[1] = load_buffer(game->mlx, MARIO_U2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[2] = load_buffer(game->mlx, MARIO_U3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[0] = load_buffer(game->mlx, MARIO_D1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[1] = load_buffer(game->mlx, MARIO_D2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[2] = load_buffer(game->mlx, MARIO_D3, &game->object[0].width, &game->object[0].height);
}

void	load_others_sprites(t_game *game)
{
	game->sprites.wall = load_buffer(game->mlx, WALL, &game->object[1].width, &game->object[1].height);
	game->sprites.coins[0] = load_buffer(game->mlx, COINS, &game->object[2].width, &game->object[2].height);
	game->sprites.coins[1] = load_buffer(game->mlx, COINS2, &game->object[2].width, &game->object[2].height);
	game->sprites.coins[2] = load_buffer(game->mlx, COINS3, &game->object[2].width, &game->object[2].height);
	game->sprites.exit = load_buffer(game->mlx, EXIT, &game->object[3].width, &game->object[3].height);
	game->sprites.enemy = load_buffer(game->mlx, ENEMY, &game->object[4].width, &game->object[4].height);
}

void	load_error(t_game *game)
{
	printf("Error loading sprites\n");
	free_game(game);
	exit(1);
}
