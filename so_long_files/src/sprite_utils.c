#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void set_mario_sprite(t_game *game, int direction_x, int direction_y);
//void draw_sprite(t_game *game, void *sprite, int x, int y);
void	draw_game(t_game *game, t_map *map);

void set_mario_sprite(t_game *game, int direction_x, int direction_y)
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


void pixel_from_argb(t_pixel *set, unsigned int color)
{
	set->r = (color >> 0);
	set->g = (color >> 8);
	set->b = (color >> 16);
	set->a = (color >> 24);
}

void	get_pixel(t_buffer *buffer, int x, int y, t_pixel *color)
{
	char	*dst;

	dst = buffer->buffer_addr + (y * buffer->line_length + x * (buffer->bits_per_pixel / 8));
	pixel_from_argb(color, *(unsigned int *)dst);	
}

unsigned int	pixel_to_int(t_pixel *set)
{
	return (set->r << 0) + (set->g << 8) + (set->b << 16) + (set->a << 24);
}

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
	static	int i;
	//mlx_clear_window(game->mlx, game->window);
	draw_bg(game);
	set_mario_sprite(game, game->player.direction_x, game->player.direction_y);
	draw_exit_enemy(game, map);
	draw_wall(game, map);
	draw_coins(game, map);
	
	mlx_put_image_to_window(game->mlx, game->window, game->buffer->buffer, 0, 0);
}