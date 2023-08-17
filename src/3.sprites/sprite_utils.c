/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:02:48 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:50 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void set_mario_sprite(t_game *game);
void	draw_game(t_game *game, t_map *map);

void set_mario_sprite(t_game *game)
{
    void *sprite;

    if (game->player.direction_x < 0)
        sprite = game->sprites.mario_l[game->current_mario_l];
	else if (game->player.direction_x > 0)
        sprite = game->sprites.mario_r[game->current_mario_r];
	else if (game->player.direction_y < 0)
        sprite = game->sprites.mario_u[game->current_mario_u];
	else if (game->player.direction_y > 0)
        sprite = game->sprites.mario_d[game->current_mario_d];
	else
        sprite = game->sprites.mario_r[game->current_mario_r];
    draw_sprite(game, sprite, &game->object[0]);
}






