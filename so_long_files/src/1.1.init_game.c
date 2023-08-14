#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	init_structs(t_game *game);
void	init_game(t_game *game, t_map *map);

void	init_structs(t_game *game)
{
	init_map_defaults(game);
	init_player_defaults(&game->player);
	init_sprites_defaults(&game->player.sprites);
}

void	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error initializing mlx\n");
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->window)
	{
		printf("Error creating window\n");
		free(game->mlx);
		exit(1);
	}
}

