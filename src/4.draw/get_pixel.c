/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:30:36 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:58 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void pixel_from_argb(t_pixel *set, unsigned int color)
{
	set->r = (color >> 0);
	set->g = (color >> 8);
	set->b = (color >> 16);
	set->a = (color >> 24);
}
