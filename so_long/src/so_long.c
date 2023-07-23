/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:14:29 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/21 18:20:49 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <mlx.h>
#include <stdlib.h>

int	encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}


int	handle_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
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
			mlx_pixel_put(data->mlx_ptr, data->window_ptr, x_pos, y_pos, rectangle->color);
			y_pos++;
		}
		x_pos++;
	}
	return (EXIT_SUCCESS);
}

int render(t_data *data)
{
	render_rectangles(data, &(t_rectangle){WIN_WIDTH - 100, WIN_HEIGHT - 100, 100, 100, encode_rgb(255, 0 , 0)});
	render_rectangles(data, &(t_rectangle){0, 0, 100, 100, encode_rgb(0, 255, 0)});
	return (0);
}

int main(void)
{
	t_data data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (EXIT_FAILURE);
	data.window_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data.window_ptr)
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.window_ptr, 2, 1L<<0, handle_key, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}