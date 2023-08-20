#include "../so_long.h"

void	init_map_defaults(t_game *game);
void	init_sprites_defaults(t_sprites *sprites);
void	init_player_defaults(t_player *player, t_sprites *sprites);

void	init_map_defaults(t_game *game)
{
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.matriz = NULL;
	game->map.pos_x = 0;
	game->map.pos_y = 0;
	game->map.moves = 0;
	game->coin_frame = 0;
	game->bg_frame = 0;
	game->mario_l_frame = 0;
	game->mario_r_frame = 0;
	game->mario_u_frame = 0;
	game->mario_d_frame = 0;
}

void	init_player_defaults(t_player *player, t_sprites *sprites)
{
	player->x = 0;
	player->y = 0;
	player->direction_x = 0;
	player->direction_y = 0;
	sprites->mario_l[0] = NULL;
	sprites->mario_l[1] = NULL;
	sprites->mario_l[2] = NULL;
	sprites->mario_r[0] = NULL;
	sprites->mario_r[1] = NULL;
	sprites->mario_r[2] = NULL;
	sprites->mario_u[0] = NULL;
	sprites->mario_u[1] = NULL;
	sprites->mario_u[2] = NULL;
	sprites->mario_d[0] = NULL;
	sprites->mario_d[1] = NULL;
	sprites->mario_d[2] = NULL;
}

void	init_sprites_defaults(t_sprites *sprites)
{
	sprites->bg[0] = NULL;
	sprites->bg[1] = NULL;
	sprites->bg[2] = NULL;
	sprites->bg[3] = NULL;
	sprites->wall = NULL;
	sprites->coins[0] = NULL;
	sprites->coins[1] = NULL;
	sprites->coins[2] = NULL;
	sprites->exit = NULL;
	sprites->height = 0;
	sprites->width = 0;
}
