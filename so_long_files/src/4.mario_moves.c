/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.mario_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:33:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/03 19:02:07 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
# include <mlx.h>
#include "../include/so_long.h"

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

void mario_move_right(t_player *player) // Juntar os 3 movimentos numa função só
{
    player->x += 5;
    player->direction_y = 0;
    
}

void mario_move_left(t_player *player)
{
    player->x -= 5;
    player->direction_y = 0;
}

void mario_move_down(t_player *player)
{
    player->y += 5;
    player->direction_y = 1;
}

void jump(t_player *player, t_map *map)
{
    if (player->on_ground)
    {
        player->direction_y = -10;
        player->jumping = 5;
        player->on_ground = 0;
    }
}


// void update_player(t_player *player, t_map *map)
// {
//     if (player->jumping)
//     {
//         player->y += player->direction_y;
//         player->direction_y -= 1;

//         if (player->y >= GROUND_HEIGHT)
//         {
//             player->y = GROUND_HEIGHT;
//             player->jumping = 0;
//             player->on_ground = 1;
//         }
//     }
// }

// void mario_move_right(t_map *map, t_player *player)
// {
//     if (map->matriz[player->y][player->x + 1] != '1')
//         player->x += 5;
//     player->direction_y = 0;    
// }

// void mario_move_left(t_map *map, t_player *player)
// {
//     if (map->matriz[player->y][player->x - 1] != '1')
//         player->x -= 5;
//     player->direction_y = 0;
// }

// void mario_move_down(t_map *map, t_player *player)
// {
//     if (map->matriz[player->y + 1][player->x] != '1')
//         player->y += 5;
//     player->direction_y = 1;
// }

// void jump(t_map *map, t_player *player)
// {
//     if (map->matriz[player->y - 1][player->x] != '1' && player->on_ground)
//     {
//         player->direction_y = -10;
//         player->jumping = 5;
//         player->on_ground = 0;
//     }
// }

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



// void draw_player(t_game *game)
// {
//     void *sprite;

//     sprite = NULL;
//     if (game->player.direction_x == 1)
//         sprite = game->player.sprites.mario_r;
//     else if (game->player.direction_x == -1)
//         sprite = game->player.sprites.mario_l;
//     else if (game->player.direction_y == 1)
//         sprite = game->player.sprites.mario_d;
//     else if (game->player.direction_y == -1)
//         sprite = game->player.sprites.mario_u;
//     mlx_put_image_to_window(game->mlx, game->window, sprite, game->player.x, game->player.y);
// }

// int main(void)
// {
//     t_game game;

//     init_game(&game, &game.map);
//     load_sprites(&game, &game.map);
//     mlx_hook(game.window, 2, 1L << 0, key_press, &game);
//     mlx_put_image_to_window(game.mlx, game.window, game.player.sprites.background, 0, 0);

//     mlx_loop(game.mlx);

//     return (0);
// }