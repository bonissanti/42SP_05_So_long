#include "../../../my_libft/include/libft.h"
# include <mlx.h>
#include "../../include/so_long.h"

void init_structs(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    game->state = PLAYING;
    game->map.moves = 0;
    game->map.player = 0;
    game->map.collectible = 0;
    game->map.c_count = 0;
    game->map.exit = 0;
    game->map.empty = 0;
    game->map.wall = 0;
    game->player.x = 0;
    game->player.y = 0;
    game->player.direction_x = 0;
    game->player.direction_y = 0;
    game->player.jumping = 0;
    game->player.on_ground = 1;
}


void update_player(t_player *player, t_map *map)
{
    if (player->jumping)
    {
        player->y += player->direction_y;
        player->direction_y -= 1;

        if (player->y <= 0)
        {
            player->y = 0;
            player->jumping = 0;
            player->on_ground = 1;
        }
    }
}

void mario_move_right(t_player *player)
{
    player->direction_x = 1;
    player->direction_y = 0;
}

void mario_move_left(t_player *player)
{
    player->direction_x = -1;
    player->direction_y = 0;
}

void mario_move_down(t_player *player)
{
    player->direction_x = 0;
    player->direction_y = 1;
}

void jump(t_player *player, t_map *map)
{
    if (player->on_ground)
    {
        player->direction_y = -10;
        player->jumping = 1;
        player->on_ground = 0;
    }
}

void exit_game(t_game *game)
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

    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free(game->mlx);

    exit(0);
}



void draw_player(t_game *game)
{
    void *sprite;

    sprite = NULL;
    if (game->player.direction_x == 1)
        sprite = game->player.sprites.mario_r;
    else if (game->player.direction_x == -1)
        sprite = game->player.sprites.mario_l;
    else if (game->player.direction_y == 1)
        sprite = game->player.sprites.mario_d;
    else if (game->player.direction_y == -1)
        sprite = game->player.sprites.mario_u;
    mlx_put_image_to_window(game->mlx, game->window, sprite, game->player.x, game->player.y);
}

int main(void)
{
    t_game game;

    init_game(&game);
    load_sprites(&game);
    mlx_hook(game.window, 2, 1L << 0, key_press, &game);
    mlx_put_image_to_window(game.mlx, game.window, game.player.sprites.background, 0, 0);

    mlx_loop(game.mlx);

    return (0);
}