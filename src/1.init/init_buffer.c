/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:39:41 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:01:43 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_buffer *create_buffer(void *mlx, int width, int height)
{
	t_buffer *img;

	img = (t_buffer *)malloc(sizeof(t_buffer));
	img->buffer = mlx_new_image(mlx, width, height);
	if (!img->buffer)
	{
		printf("Error creating buffer\n");
		free(img);
		return (NULL);
	}
	img->buffer_addr = mlx_get_data_addr(img->buffer, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}


t_buffer	*load_buffer(void *mlx, char *path, int *width, int *height)
{
	t_buffer	*img;

	img = (t_buffer *)malloc(sizeof(t_buffer));
	img->buffer = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!img->buffer)
	{
		printf("Error loading buffer\n");
		free(img);
		return (NULL);
	}
	img->buffer_addr = mlx_get_data_addr(img->buffer, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}


void	object_set(t_object *object, int x, int y, int width, int height)
{
	if (!object)
		return ;
	object->x = x;
	object->y = y;
	object->width = width;
	object->height = height;
}