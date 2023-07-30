#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"

void free_map(t_map *map)
{
    int row;

    row = 0;
    while (row < map->rows)
    {
        free(map->matriz[row]);
        row++;
    }
    free(map->matriz);
}

void free_sprites(t_game *game)
{
    mlx_destroy_image(game->mlx, game->player.sprites.background);
    mlx_destroy_image(game->mlx, game->player.sprites.mario_l);
    mlx_destroy_image(game->mlx, game->player.sprites.mario_r);
    mlx_destroy_image(game->mlx, game->player.sprites.mario_u);
    mlx_destroy_image(game->mlx, game->player.sprites.mario_d);
    free(game->player.sprites.background);
    free(game->player.sprites.mario_l);
    free(game->player.sprites.mario_r);
    free(game->player.sprites.mario_u);
    free(game->player.sprites.mario_d);
}

void free_game(t_game *game, t_map *map)
{
    free_map(map);
    free_sprites(game);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
}