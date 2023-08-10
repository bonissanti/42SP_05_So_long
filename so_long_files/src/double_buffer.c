/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:14 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/10 17:23:39 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

// void *double_buffering(t_game *game)
// {
// 	int bits_per_pixel;
// 	int line_length;
// 	int endian;

// 	game->buffer = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
// 	game->addr = mlx_get_data_addr(game->buffer, &bits_per_pixel, &line_length, &endian);

// 	return(game->buffer);
// }