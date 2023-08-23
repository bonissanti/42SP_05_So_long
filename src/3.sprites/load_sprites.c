/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:37 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 15:46:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_bg_sprites(t_game *game);
void	load_mario_sprites(t_game *game);
void	load_others_sprites(t_game *game);
void	load_error(t_game *game);

/**
 * Function: Load sprites
 * -----------------
 * This function calls the functions to load the sprites. It will load the
 * background sprites, mario sprites and other sprites. If any sprite is not
 * loaded, it will call the load_error function.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

void	load_sprites(t_game *game, t_map *map)
{
	load_bg_sprites(game);
	load_mario_sprites(game);
	load_others_sprites(game);
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
	{
		load_error(game);
	}
	find_start_position(&game->map, &game->map.pos_x, &game->map.pos_y);
	game->player.x = game->map.pos_x * SPRITE_SIZE;
	game->player.y = game->map.pos_y * SPRITE_SIZE;
	draw_game(game, map, game->objects, game->num_obj);
}

/**
 * Function: Load bg sprites
 * -----------------
 * This function loads the background sprites.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	load_bg_sprites(t_game *game)
{
	int	width;
	int	height;

	game->sprites.bg[0] = mlx_xpm_file_to_image(game->mlx, BG, &width, &height);
	game->sprites.bg[1] = mlx_xpm_file_to_image(game->mlx, BG2, &width,
			&height);
	game->sprites.bg[2] = mlx_xpm_file_to_image(game->mlx, BG3, &width,
			&height);
	game->sprites.bg[3] = mlx_xpm_file_to_image(game->mlx, BG4, &width,
			&height);
}

/**
 * Function: Load mario sprites
 * -----------------
 * This function loads the mario sprites.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	load_mario_sprites(t_game *game)
{
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
}

/**
 * Function: Load other sprites
 * -----------------
 * This function loads the other sprites, like the wall, coins, exit and
 * enemy.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	load_others_sprites(t_game *game)
{
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
}

/**
 * Function: Load error
 * -----------------
 * This function is called when any sprite is not loaded. It will print an
 * error message and free the game struct.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	load_error(t_game *game)
{
	ft_printf("Error loading sprites\n");
	free_game(game);
	exit(1);
}
