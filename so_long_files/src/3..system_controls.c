/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3..system_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:40:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/08 12:22:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_SUCCESS);
    }

    if (keycode == KEY_A || keycode == KEY_LEFT)
    {
        game->map.moves++;
        printf("Moves: %d\n", game->map.moves);
        game->player.x -= 44;
        game->player.direction_x = -1;
        game->player.direction_y = 0;
    }
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
    {
        game->map.moves++;
        printf("Moves: %d\n", game->map.moves);
        game->player.x += 44;
        game->player.direction_x = 1;
        game->player.direction_y = 0;
    }
    else if (keycode == KEY_W || keycode == KEY_UP)
    {
        game->map.moves++;
        game->player.y -= 44;
        printf("Moves: %d\n", game->map.moves);
        game->player.direction_x = 0;
        game->player.direction_y = -1;
    }
    else if (keycode == KEY_S || keycode == KEY_DOWN)
    {
        game->map.moves++;
        printf("Moves: %d\n", game->map.moves);
        game->player.y += 44;
        game->player.direction_x = 0;
        game->player.direction_y = 1;
    }

    
    draw_game(game, &game->map);
    

    return (0);
}



int is_wall(t_map *map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->columns || y >= map->rows)
        return (1);
    return (map->matriz[y][x] == '1');
}


void update_game(t_game *game)
{
    int next_x;
    int next_y;

    next_x = game->player.x;
    next_y = game->player.y;

    if (game->player.direction_x == 1)
        next_x++;
    else if (game->player.direction_x == -1)
        next_x--;
    else if (game->player.direction_y == 1)
        next_y++;
    else if (game->player.direction_y == -1)
        next_y--;
    
    if (!is_wall(&game->map, next_x, next_y))
    {
        game->player.x = next_x;
        game->player.y = next_y;
    }
}

int game_loop(t_game *game)
{
    // mlx_clear_window(game->mlx, game->window);
    update_game(game);
    draw_game(game, &game->map);
    return (0);
}


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

