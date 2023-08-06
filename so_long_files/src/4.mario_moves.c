/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.mario_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:33:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/04 14:36:55 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
# include <mlx.h>
#include "../include/so_long.h"


void mario_move_right(t_game *game)
{
    game->player.x += 1;
    game->player.direction_x = 1;
    game->player.direction_y = 0;

    game->map.moves++;
    printf("moves: %d\n", game->map.moves);
    draw_game(game, &game->map);

    if (game->map.matriz[game->player.y][game->player.x] == 'E')
        game->state = VICTORY;
    else if (game->map.matriz[game->player.y][game->player.x] == '1')
        game->state = DEFEAT;
    else
        game->state = PLAYING;
}


void mario_move_left(t_game *game)
{
    game->player.x -= 1;
    game->player.direction_x = -1;
    game->player.direction_y = 0;

    game->map.moves++;
    printf("moves: %d\n", game->map.moves);
    draw_game(game, &game->map);

    if (game->map.matriz[game->player.y][game->player.x] == 'E')
        game->state = VICTORY;
    else if (game->map.matriz[game->player.y][game->player.x] == '1')
        game->state = DEFEAT;
    else
        game->state = PLAYING;
}

void mario_move_down(t_game *game)
{
    game->player.y += 1;
    game->player.direction_y = 1;
    game->player.direction_x = 0;

    game->map.moves++;
    printf("moves: %d\n", game->map.moves);
    draw_game(game, &game->map);

    if (game->map.matriz[game->player.y][game->player.x] == 'E')
        game->state = VICTORY;
    else if (game->map.matriz[game->player.y][game->player.x] == '1')
        game->state = DEFEAT;
    else
        game->state = PLAYING;

    if (game->map.matriz[game->player.y][game->player.x] == 'E')
        game->state = VICTORY;
    else if (game->map.matriz[game->player.y][game->player.x] == '1')
        game->state = DEFEAT;
    else
        game->state = PLAYING;
}

void mario_move_up(t_game *game)
{
    game->player.y -= 1;
    game->player.direction_y = -1;
    game->player.direction_x = 0;

    game->map.moves++;
    printf("moves: %d\n", game->map.moves);
    draw_game(game, &game->map);

    if (game->map.matriz[game->player.y][game->player.x] == 'E')
        game->state = VICTORY;
    else if (game->map.matriz[game->player.y][game->player.x] == '1')
        game->state = DEFEAT;
    else
        game->state = PLAYING;
}   

void update_player_sprite(t_game *game)
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

void redraw_mario(t_game *game, int new_x, int new_y)
{
    game->player.x = new_x;
    game->player.y = new_y;
    if (new_x < game->player.x)
        game->player.direction_x = -1;
    else if (new_x > game->player.x)
        game->player.direction_x = 1;
    else if (new_y < game->player.y)
        game->player.direction_y = -1;
    else if (new_y > game->player.y)
        game->player.direction_y = 1;

    update_player_sprite(game);

    game->map.matriz[game->player.y][game->player.x] = '0';
    game->map.matriz[new_y][new_x] = 'P';
    draw_game(game, &game->map);
}



// void jump(t_player *player)
// {
//     if (player->on_ground)
//     {
//         player->direction_y = -10;
//         player->jumping = 5;
//         player->on_ground = 0;
//     }
// }


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

    // if (map->matriz[player->y][player->x - 1] != '1')


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