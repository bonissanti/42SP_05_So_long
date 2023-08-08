/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.mario_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:33:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/07 19:47:44 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"


void handle_player_movement(t_game *game, int new_x, int new_y)
{
    if (game->map.matriz[new_x][new_y] == 'X' || game->map.matriz[new_x][new_y] == 'E')
    {
        if (game->map.matriz[new_x][new_y] == 'E')
            printf("Game Over\n");
        else
            printf("You won!\n");
        exit_game(game);
    }
    game->player.x = new_x;
    game->player.y = new_y;

    // update_player_sprite(game);

    game->map.matriz[new_x][new_y] = 'P';
    game->map.matriz[game->player.x][game->player.y] = '0';

    draw_game(game, &game->map);

    
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

