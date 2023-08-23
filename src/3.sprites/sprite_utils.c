/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:43 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 18:14:36 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_mario_sprite(t_game *game);
void	draw_sprite(t_game *game, void *sprite, int x, int y);
void	draw_game(t_game *game, t_map *map, t_object *object, int num_obj);
void	animate_sprites(t_game *game);

/**
 * Function: Set mario sprite
 * -----------------
 * This function will set the mario sprite, according to the direction of the
 * player. If the player is moving to the left, it will set the mario sprite to
 * the left. If the player is moving to the right, it will set the mario sprite
 * to the right. If the player is moving up, it will set the mario sprite to the
 * up. If the player is moving down, it will set the mario sprite to the down.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

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

/**
 * Function: Draw sprite
 * -----------------
 * This function will draw a sprite in the window, in the position x and y.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *sprite - Pointer to the sprite.
 * @param: x - Position x in the window.
 * @param: y - Position y in the window.
 *
 * @return: Is a void function.
 *
 */

void	draw_sprite(t_game *game, void *sprite, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, sprite, x, y);
}

/**
 * Function: Draw game
 * -----------------
 * This function will draw the game. It will draw the background, the map, the
 * objects and the mario. It will also clear the window before drawing the game.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *sprite - Pointer to the sprite.
 * @param: x - Position x in the window.
 * @param: y - Position y in the window.
 *
 * @return: Is a void function.
 *
 */

void	draw_game(t_game *game, t_map *map, t_object *object, int num_obj)
{
	mlx_clear_window(game->mlx, game->window);
	draw_background(game);
	draw_map_objects(game, object, num_obj);
	draw_wall(game, map);
	draw_mario(game, map);
}

/**
 * Function: Animate sprites
 * -----------------
 * This function will animate the sprites. It will change the frame of the
 * sprite, so it will look like it is moving.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	animate_sprites(t_game *game)
{
	game->coin_frame = (game->coin_frame + 1) % 3;
	game->bg_frame = (game->bg_frame + 1) % 4;
	game->mario_l_frame = (game->mario_l_frame + 1) % 3;
	game->mario_r_frame = (game->mario_r_frame + 1) % 3;
	game->mario_u_frame = (game->mario_u_frame + 1) % 3;
	game->mario_d_frame = (game->mario_d_frame + 1) % 3;
}
