<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:02:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:36 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
#include "../so_long.h"

void	load_bg_sprites(t_game *game);
void	load_mario_sprites(t_game *game);
void	load_others_sprites(t_game *game);
<<<<<<< HEAD
void	load_error(t_game *game);
=======
void    load_error(t_game *game);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4

void	load_sprites(t_game *game, t_map *map)
{
	load_bg_sprites(game);
	load_mario_sprites(game);
	load_others_sprites(game);
<<<<<<< HEAD
	if (!game->sprites.bg[0] || !game->sprites.bg[1] || !game->sprites.bg[2]
		|| !game->sprites.bg[3] || !game->sprites.mario_r[0]
		|| !game->sprites.mario_r[1] || !game->sprites.mario_r[2]
		|| !game->sprites.mario_d[0] || !game->sprites.mario_d[1]
		|| !game->sprites.mario_d[2] || !game->sprites.mario_l[0]
		|| !game->sprites.mario_l[1] || !game->sprites.mario_l[2]
		|| !game->sprites.mario_u[0] || !game->sprites.mario_u[1]
		|| !game->sprites.mario_u[2] || !game->sprites.wall
		|| !game->sprites.coins[0] || !game->sprites.coins[1]
		|| !game->sprites.coins[2] || !game->sprites.exit
		|| !game->sprites.enemy)
=======
	if (!game->sprites.bg[0] || !game->sprites.bg[1]
		|| !game->sprites.bg[2] || !game->sprites.bg[3]
		|| !game->sprites.mario_r[0] || !game->sprites.mario_r[1]
		|| !game->sprites.mario_r[2] || !game->sprites.mario_d[0]
		|| !game->sprites.mario_d[1] || !game->sprites.mario_d[2]
		|| !game->sprites.mario_l[0] || !game->sprites.mario_l[1]
		|| !game->sprites.mario_l[2] || !game->sprites.mario_u[0]
		|| !game->sprites.mario_u[1] || !game->sprites.mario_u[2]
		|| !game->sprites.wall || !game->sprites.coins[0]
		|| !game->sprites.coins[1] || !game->sprites.coins[2]
		|| !game->sprites.exit || !game->sprites.enemy)
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
	{
		load_error(game);
	}
	find_start_position(&game->map, &game->map.pos_x, &game->map.pos_y);
<<<<<<< HEAD
	game->player.x = game->map.pos_x * SPRITE_SIZE;
	game->player.y = game->map.pos_y * SPRITE_SIZE;
	draw_game(game, map, game->objects, game->num_obj);
=======
	game->object->x = game->map.pos_x * SPRITE_SIZE;
	game->object->y = game->map.pos_y * SPRITE_SIZE;
	draw_game(game, map);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}

void	load_bg_sprites(t_game *game)
{
	int	width;
	int	height;

<<<<<<< HEAD
	game->sprites.bg[0] = mlx_xpm_file_to_image(game->mlx, BG, &width, &height);
	game->sprites.bg[1] = mlx_xpm_file_to_image(game->mlx, BG2, &width,
			&height);
	game->sprites.bg[2] = mlx_xpm_file_to_image(game->mlx, BG3, &width,
			&height);
	game->sprites.bg[3] = mlx_xpm_file_to_image(game->mlx, BG4, &width,
			&height);
=======
	game->sprites.bg[0] = load_buffer(game->mlx, BG, &width, &height);
	game->sprites.bg[1] = load_buffer(game->mlx, BG2, &width, &height);
	game->sprites.bg[2] = load_buffer(game->mlx, BG3, &width, &height);
	game->sprites.bg[3] = load_buffer(game->mlx, BG4, &width, &height);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}

void	load_mario_sprites(t_game *game)
{
<<<<<<< HEAD
	game->sprites.mario_r[0] = mlx_xpm_file_to_image(game->mlx, MARIO_R1,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_r[1] = mlx_xpm_file_to_image(game->mlx, MARIO_R2,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_r[2] = mlx_xpm_file_to_image(game->mlx, MARIO_R3,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_l[0] = mlx_xpm_file_to_image(game->mlx, MARIO_L1,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_l[1] = mlx_xpm_file_to_image(game->mlx, MARIO_L2,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_l[2] = mlx_xpm_file_to_image(game->mlx, MARIO_L3,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_u[0] = mlx_xpm_file_to_image(game->mlx, MARIO_U1,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_u[1] = mlx_xpm_file_to_image(game->mlx, MARIO_U2,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_u[2] = mlx_xpm_file_to_image(game->mlx, MARIO_U3,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_d[0] = mlx_xpm_file_to_image(game->mlx, MARIO_D1,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_d[1] = mlx_xpm_file_to_image(game->mlx, MARIO_D2,
			&game->sprites.width, &game->sprites.height);
	game->sprites.mario_d[2] = mlx_xpm_file_to_image(game->mlx, MARIO_D3,
			&game->sprites.width, &game->sprites.height);
=======
	game->sprites.mario_r[0] = load_buffer(game->mlx, MARIO_R1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_r[1] = load_buffer(game->mlx, MARIO_R2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_r[2] = load_buffer(game->mlx, MARIO_R3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[0] = load_buffer(game->mlx, MARIO_L1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[1] = load_buffer(game->mlx, MARIO_L2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_l[2] = load_buffer(game->mlx, MARIO_L3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[0] = load_buffer(game->mlx, MARIO_U1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[1] = load_buffer(game->mlx, MARIO_U2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_u[2] = load_buffer(game->mlx, MARIO_U3, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[0] = load_buffer(game->mlx, MARIO_D1, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[1] = load_buffer(game->mlx, MARIO_D2, &game->object[0].width, &game->object[0].height);
	game->sprites.mario_d[2] = load_buffer(game->mlx, MARIO_D3, &game->object[0].width, &game->object[0].height);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}

void	load_others_sprites(t_game *game)
{
<<<<<<< HEAD
	int	width;
	int	height;

	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, &width,
			&height);
	game->sprites.coins[0] = mlx_xpm_file_to_image(game->mlx, COINS, &width,
			&height);
	game->sprites.coins[1] = mlx_xpm_file_to_image(game->mlx, COINS2, &width,
			&height);
	game->sprites.coins[2] = mlx_xpm_file_to_image(game->mlx, COINS3, &width,
			&height);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width,
			&height);
	game->sprites.enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, &width,
			&height);
=======
	game->sprites.wall = load_buffer(game->mlx, WALL, &game->object[1].width, &game->object[1].height);
	game->sprites.coins[0] = load_buffer(game->mlx, COINS, &game->object[2].width, &game->object[2].height);
	game->sprites.coins[1] = load_buffer(game->mlx, COINS2, &game->object[2].width, &game->object[2].height);
	game->sprites.coins[2] = load_buffer(game->mlx, COINS3, &game->object[2].width, &game->object[2].height);
	game->sprites.exit = load_buffer(game->mlx, EXIT, &game->object[3].width, &game->object[3].height);
	game->sprites.enemy = load_buffer(game->mlx, ENEMY, &game->object[4].width, &game->object[4].height);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}

void	load_error(t_game *game)
{
<<<<<<< HEAD
	ft_printf("Error loading sprites\n");
=======
	printf("Error loading sprites\n");
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
	free_game(game);
	exit(1);
}
