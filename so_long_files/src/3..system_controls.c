/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3..system_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:40:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/09 15:24:07 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"


int key_press(int keycode, t_game *game)
{
    int next_x;
    int next_y;

    next_x = game->player.x;
    next_y = game->player.y;

    if (keycode == KEY_ESC)
    {
        printf("You closed the window!\n");
        free_game(game);
    }

    if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        next_x -= 5;
        // game->player.x -= 5;
        game->player.direction_x = -1;
        game->player.direction_y = 0;
    }
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        next_x += 5;
        // game->player.x += 5;
        game->player.direction_x = 1;
        game->player.direction_y = 0;
    }
    else if (keycode == KEY_W || keycode == KEY_UP)
    {
        next_y -= 5;
        // game->player.y -= 5;
        game->player.direction_x = 0;
        game->player.direction_y = -1;
    }
    else if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        next_y += 5;
        // game->player.y += 5;
        game->player.direction_x = 0;
        game->player.direction_y = 1;
    }

    if (check_next_position(next_x, next_y, game))
    {
        game->player.x = next_x;
        game->player.y = next_y;
    }
    draw_game(game, &game->map);
    

    return (0);
}

int check_next_position(int next_x, int next_y, t_game *game)
{
    char next_pos;
    if (next_x < 0 || next_x >= game->map.columns * SPRITE_SIZE || next_y < 0 || next_y >= game->map.rows * SPRITE_SIZE)
        return (0);

    next_pos = game->map.matriz[next_y / 44][next_x / 44];

    if (next_pos == '1') { // Wall
        printf("You hit a wall!\n");
        return (0);
    } else if (next_pos == 'C') { // Coin
        game->map.c_count--;
        game->map.matriz[next_y / 44][next_x / 44] = '0';
    } else if (next_pos == 'E') { // Exit
        if (game->map.c_count == 0) {
            printf("You win!\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("You must collect all coins first!\n");
            return (0);
        }
    } else if (next_pos == 'X') { // Enemy
        printf("You hit an enemy! Game over.\n");
        exit(EXIT_FAILURE);
    }

    return (1);
}



// int is_wall(t_map *map, int x, int y)
// {
//     if (x < 0 || y < 0 || x >= map->columns || y >= map->rows)
//         return (1);
//     return (map->matriz[y][x] == '1');
// }


// void update_game(t_game *game)
// {
//     int next_x;
//     int next_y;

//     next_x = game->player.x;
//     next_y = game->player.y;

//     if (game->player.direction_x == 1)
//         next_x++;
//     else if (game->player.direction_x == -1)
//         next_x--;
//     else if (game->player.direction_y == 1)
//         next_y++;
//     else if (game->player.direction_y == -1)
//         next_y--;
    
//     if (!is_wall(&game->map, next_x, next_y))
//     {
//         game->player.x = next_x;
//         game->player.y = next_y;
//     }
// }

// int game_loop(t_game *game)
// {
//     // mlx_clear_window(game->mlx, game->window);
//     update_game(game);
//     draw_game(game, &game->map);
//     return (0);
// }


// int game_loop(t_game *game)
// {
//     update_game(game);
//     draw_game(game, &game->map);

//     return (0);
// }


int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    exit(EXIT_SUCCESS);
    return (0);
}

    // mlx_destroy_display(game->mlx);
    // free(game->mlx);

