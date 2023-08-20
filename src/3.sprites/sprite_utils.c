<<<<<<< HEAD
#include "../so_long.h"

void	set_mario_sprite(t_game *game);
void	draw_sprite(t_game *game, void *sprite, int x, int y);
void	draw_game(t_game *game, t_map *map, t_object *object, int num_obj);
void	animate_sprites(t_game *game);

void	set_mario_sprite(t_game *game)
{
	void	*sprite;

	if (game->player.direction_x < 0)
		sprite = game->sprites.mario_l[game->mario_l_frame];
	else if (game->player.direction_x > 0)
		sprite = game->sprites.mario_r[game->mario_r_frame];
	else if (game->player.direction_y < 0)
		sprite = game->sprites.mario_u[game->mario_u_frame];
	else if (game->player.direction_y > 0)
		sprite = game->sprites.mario_d[game->mario_d_frame];
	else
		sprite = game->sprites.mario_r[game->mario_r_frame];
	draw_sprite(game, sprite, game->player.x, game->player.y);
}

void	draw_sprite(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, sprite, x, y);
}

void	draw_game(t_game *game, t_map *map, t_object *object, int num_obj)
{
	mlx_clear_window(game->mlx, game->window);
	draw_background(game);
	draw_map_objects(game, object, num_obj);
	draw_wall(game, map);
	draw_mario(game, map);
}

void	animate_sprites(t_game *game)
{
	game->coin_frame = (game->coin_frame + 1) % 3;
	game->bg_frame = (game->bg_frame + 1) % 4;
	game->mario_l_frame = (game->mario_l_frame + 1) % 3;
	game->mario_r_frame = (game->mario_r_frame + 1) % 3;
	game->mario_u_frame = (game->mario_u_frame + 1) % 3;
	game->mario_d_frame = (game->mario_d_frame + 1) % 3;
}
=======
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






>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
