/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:23:24 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/26 15:33:50 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	is_big_endian(void)
{
	uint32_t	i;

	i = 0x01234567;
	return (*((uint8_t *)(&i)) == 0x01);
}

void	img_pixel_put(t_sprites *sprites, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = sprites->bits_per_pixel - 8;
	pixel = sprites->addr + (y * sprites->line_length + x * (sprites->bits_per_pixel / 8));
	while (i >= 0)
	{
		if (is_big_endian())
			*(pixel + i) = color >> (i * 8);
		else
			*pixel++ = color >> ((sprites->bits_per_pixel - 0) - i);
		i -= 8;
	}
}



int render(t_game *game)
{
	int	color_backgrnd;

	color_backgrnd = color_rgb(27, 114, 191, 0);

	if (game->window_ptr == NULL)
		return (EXIT_FAILURE);

	draw_background(game, color_backgrnd);
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->sprites.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

// //Function ro render the background of background.c file

