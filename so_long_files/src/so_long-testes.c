/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long-testes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:14:29 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/25 12:10:01 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdint.h>



int is_big_endian(void)
{
	uint32_t i = 0x01234567;

	return (*((uint8_t *)(&i)) == 0x01);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (is_big_endian())
			*(pixel + i) = color >> (i * 8);
		else
			*pixel++ = color >> ((img->bits_per_pixel - 8) - i);
		i -= 8;	
	}
}

int render_rectangles(t_data *data, t_rectangle *rectangle)
{
	int x_pos;
	int y_pos;

	if (data->window_ptr == NULL)
		return (EXIT_FAILURE);
	
	x_pos = rectangle->x;
	while (x_pos < rectangle->x + rectangle->width)
	{
		y_pos = rectangle->y;
		while (y_pos < rectangle->y + rectangle->height)
		{
			img_pixel_put(&(data->img), x_pos, y_pos, rectangle->color);
			y_pos++;
		}
		x_pos++;
	}
	return (EXIT_SUCCESS);
}

void render_background(t_data *data, int color)
{
	int x_pos;
	int y_pos;

	if (data->window_ptr == NULL)
		return ;

	x_pos = 0;
	while (x_pos < WIN_WIDTH)
	{
		y_pos = 0;
		while (y_pos < WIN_HEIGHT)
		{
			img_pixel_put(&(data->img), x_pos, y_pos, color);
			y_pos++;
		}
		x_pos++;
	}	
}


int	handle_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}


int render(t_data *data)
{
	if (data->window_ptr == NULL)
		return (EXIT_FAILURE);
	render_background(data, encode_rgb(65, 72, 104));
	render_rectangles(data, &(t_rectangle){WIN_WIDTH - 100, WIN_HEIGHT - 100, 100, 100, encode_rgb(255, 0 , 0)});
	render_rectangles(data, &(t_rectangle){0, 0, 100, 100, encode_rgb(0, 255 , 0)});

	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img.img_ptr, 0, 0);
	if (data->window_ptr == NULL)
		return (EXIT_FAILURE);

	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (EXIT_FAILURE);

	data.window_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Super Mario World | 42 edition");
	if (data.window_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}

	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (data.img.img_ptr == NULL)
	{
		mlx_destroy_window(data.mlx_ptr, data.window_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}

	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (data.img.addr == NULL)
	{
		mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
		mlx_destroy_window(data.mlx_ptr, data.window_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (EXIT_FAILURE);
	}

	mlx_hook(data.window_ptr, 2, 1L<<0, handle_key, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.img_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	
	return (0);
}