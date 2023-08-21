/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:32 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 10:49:33 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_background(t_game *game);
void	draw_mario(t_game *game, t_map *map);

void	draw_background(t_game *game)
{
	void	*sprite;

	sprite = game->sprites.bg[game->bg_frame];
	mlx_put_image_to_window(game->mlx, game->window, sprite, 0, 0);
}

void	draw_object(t_game *game, t_object *object)
{
	mlx_put_image_to_window(game->mlx, game->window, object->sprite, object->x
		* SPRITE_SIZE, object->y * SPRITE_SIZE);
}

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
		}
		i++;
	}
}
