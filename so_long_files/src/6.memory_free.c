/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.memory_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:01:48 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/09 18:20:11 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"


void free_matriz(int **visited, int rows)
{
    int row;

    row = 0;
    while (row < rows)
    {
        free(visited[row]);
        row++;
    }
    free(visited);
}

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
    mlx_destroy_image(game->mlx, game->player.sprites.wall);
    mlx_destroy_image(game->mlx, game->player.sprites.collectible);
    mlx_destroy_image(game->mlx, game->player.sprites.exit);    
}

void free_game(t_game *game)
{
    free_sprites(game);
    mlx_destroy_window(game->mlx, game->window);
    mlx_destroy_display(game->mlx);
    free_map(&game->map);
    free(game->mlx);
    exit(EXIT_SUCCESS);
}