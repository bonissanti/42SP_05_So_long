#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	init_structs(t_game *game);
void	init_game(t_game *game, t_map *map);

void	init_structs(t_game *game)
{
	init_map_defaults(game);
	init_sprites_defaults(&game->sprites);
	init_player_defaults(&game->player, &game->sprites);
}

void buffer_clear(t_buffer *buffer, int color)
{
	char	*dst;
	int		pos;

	pos = -1;
	while (++pos < WIN_WIDTH * WIN_HEIGHT)
	{
		dst = buffer->buffer_addr + ((pos / WIN_WIDTH) *buffer->line_length + (pos % WIN_WIDTH) * (buffer->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_game(t_game *game, t_map *map)
{
	t_buffer *img;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error initializing mlx\n");
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->window)
	{
		printf("Error creating window\n");
		free(game->mlx);
		exit(1);
	}
	game->buffer = create_buffer(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	buffer_clear(game->buffer, 0x00FFFFFF);
}

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
