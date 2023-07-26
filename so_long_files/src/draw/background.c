/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:35:52 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/26 15:33:07 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	draw_background(t_game *game, int color)
{
	int	x_pos;
	int	y_pos;

	if (game->window_ptr == NULL)
		return (EXIT_FAILURE);
	x_pos = 0;
	while (x_pos < WIN_WIDTH)
	{
		y_pos = 0;
		while (y_pos < WIN_HEIGHT)
		{
			img_pixel_put(&(game->sprites), x_pos, y_pos, color);
			y_pos++;
		}
		x_pos++;
	}
	return (EXIT_SUCCESS);
}
