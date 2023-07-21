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

int render(t_data *data)
{
	int color;

	color = encode_rgb(255, 255, 0);

	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 400, 300, color);
	return (0);
}

int main(void)
{
	t_data data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data.win_ptr)
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, handle_key, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}