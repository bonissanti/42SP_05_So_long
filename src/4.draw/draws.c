/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:32:05 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 18:07:28 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_bg(t_game *game)
{
	int		pos;
	t_pixel	color;

	pos = -1;
	while (++pos < WIN_WIDTH * WIN_HEIGHT)
	{
		get_pixel(game->sprites.bg[game->current_bg], pos % WIN_WIDTH, pos / WIN_WIDTH, &color);
		*(unsigned int *)(game->buffer->buffer_addr + pos * (game->buffer->bits_per_pixel / 8)) = pixel_to_int(&color);
	}
}

void draw_sprite(t_game *game, void *sprite, t_object *obj)
{
	int 	row;
	int 	col;
	t_pixel	color;
	t_buffer *img;
	char	*dst;

	img = sprite;
	col = -1;
	while (++col < obj->height)
	{
		row = -1;
		while (++row < obj->width)
		{
			get_pixel(img, row, col, &color);			
			dst = game->buffer->buffer_addr + ((col + obj->y) * game->buffer->line_length + (row + obj->x) * (game->buffer->bits_per_pixel / 8));
			*(unsigned int *)dst = pixel_to_int(&color);
		}
	}
}

void	draw_game(t_game *game, t_map *map)
{
	// mlx_clear_window(game->mlx, game->window);
	draw_bg(game);
	set_mario_sprite(game);
	draw_exit_enemy(game, map);
	draw_wall(game, map);
	draw_coins(game, map);
	
	mlx_put_image_to_window(game->mlx, game->window, game->buffer->buffer, 0, 0);
}