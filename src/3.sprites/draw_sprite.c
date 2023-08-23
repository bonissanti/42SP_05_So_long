/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:32 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 15:35:27 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_game *game);
void	draw_mario(t_game *game, t_map *map);

/**
 * Function: Draw background
 * -----------------
 * This is a function draws background of the game. It will draw the background
 * of the game, according to the frame of the background.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

void	draw_background(t_game *game)
{
	void	*sprite;

	sprite = game->sprites.bg[game->bg_frame];
	mlx_put_image_to_window(game->mlx, game->window, sprite, 0, 0);
}

/**
 * Function: Mlx hooks
 * -----------------
 * This is a function that calls the mlx_loop_hook function and the mlx_hook
 * function. The mlx_loop_hook function is used to looping the game, mlx_hook
 * function is used to handle the events, like key press and close window.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *object - Pointer to the object struct.
 *
 * @return: Is a void function.
 *
 */

void	draw_object(t_game *game, t_object *object)
{
	mlx_put_image_to_window(game->mlx, game->window, object->sprite, object->x
		* SPRITE_SIZE, object->y * SPRITE_SIZE);
}

/**
 * Function: Mlx hooks
 * -----------------
 * This is a function that calls the mlx_loop_hook function and the mlx_hook
 * function. The mlx_loop_hook function is used to looping the game, mlx_hook
 * function is used to handle the events, like key press and close window.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

void	draw_mario(t_game *game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'P')
				set_mario_sprite(game);
			col++;
		}
		row++;
	}
}

/**
 * Function: Draw wall
 * -----------------
 * This is a function draws wall of the game. It will draw the wall of the game,
 * according to the frame of the wall.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *map - Pointer to the map struct.
 *
 * @return: This is a void function.
 *
 */

void	draw_wall(t_game *game, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == '1')
				draw_sprite(game, game->sprites.wall, col * SPRITE_SIZE, row
					* SPRITE_SIZE);
			col++;
		}
		row++;
	}
}

/**
 * Function: Draw map objects
 * -----------------
 * This is a function draws the objects of the game. It will draw the objects of
 * the game, according to the frame of the object, the x and y coordinates of the
 * object, and the symbol of the object.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *objects - Pointer to the object struct.
 * @param: num_obj - Number of objects.
 *
 * @return: Is a void function.
 *
 */

void	draw_map_objects(t_game *game, t_object *objects, int num_obj)
{
	int			i;
	t_object	*object;

	i = 0;
	object = &objects[i];
	while (i < num_obj)
	{
		object = &objects[i];
		if (!object->is_collected)
		{
			if (object->symbol == 'C')
				draw_sprite(game, game->sprites.coins[game->coin_frame],
					object->x * SPRITE_SIZE, object->y * SPRITE_SIZE);
			else if (object->symbol == 'E')
				draw_sprite(game, game->sprites.exit, object->x * SPRITE_SIZE,
					object->y * SPRITE_SIZE);
			else if (object->symbol == 'X')
				draw_sprite(game, game->sprites.enemy, object->x * SPRITE_SIZE,
					object->y * SPRITE_SIZE);
			else if (object->symbol == '0')
				draw_background(game);
		}
		i++;
	}
}
