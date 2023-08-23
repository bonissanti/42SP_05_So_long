/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:01:48 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/23 10:46:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: Free matriz
 * -----------------
 * This functions frees the matriz visited, which is used to check if the player
 * is in a valid position.
 * 
 * @param: **visited - Pointer to the matriz visited.
 * @param: rows - Number of rows of the matriz.
 *
 * @return: Is a void function.
 *
 */

void	free_matriz(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/**
 * Function: Free map
 * -----------------
 * This functions frees the matriz map, which is used to store the map.
 * 
 * @param: *map
 *
 * @return: Is a void function.
 *
 */

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->matriz[i]);
		i++;
	}
	free(map->matriz);
}

/**
 * Function: Free player sprites
 * -----------------
 * This functions frees the sprites of the player, if they are not NULL.
 * 
 * @param: *map
 *
 * @return: Is a void function.
 *
 */

void	free_player_sprites(t_game *game)
{
	if (game->sprites.mario_l[0])
		mlx_destroy_image(game->mlx, game->sprites.mario_l[0]);
	if (game->sprites.mario_l[1])
		mlx_destroy_image(game->mlx, game->sprites.mario_l[1]);
	if (game->sprites.mario_l[2])
		mlx_destroy_image(game->mlx, game->sprites.mario_l[2]);
	if (game->sprites.mario_r[0])
		mlx_destroy_image(game->mlx, game->sprites.mario_r[0]);
	if (game->sprites.mario_r[1])
		mlx_destroy_image(game->mlx, game->sprites.mario_r[1]);
	if (game->sprites.mario_r[2])
		mlx_destroy_image(game->mlx, game->sprites.mario_r[2]);
	if (game->sprites.mario_u[0])
		mlx_destroy_image(game->mlx, game->sprites.mario_u[0]);
	if (game->sprites.mario_u[1])
		mlx_destroy_image(game->mlx, game->sprites.mario_u[1]);
	if (game->sprites.mario_u[2])
		mlx_destroy_image(game->mlx, game->sprites.mario_u[2]);
	if (game->sprites.mario_d[0])
		mlx_destroy_image(game->mlx, game->sprites.mario_d[0]);
	if (game->sprites.mario_d[1])
		mlx_destroy_image(game->mlx, game->sprites.mario_d[1]);
	if (game->sprites.mario_d[2])
		mlx_destroy_image(game->mlx, game->sprites.mario_d[2]);
}

/**
 * Function: Free sprites
 * -----------------
 * This functions frees the sprites of the game, if they are not NULL.
 * 
 * @param: *map
 *
 * @return: Is a void function.
 *
 */

void	free_sprites(t_game *game)
{
	if (game->sprites.bg[0])
		mlx_destroy_image(game->mlx, game->sprites.bg[0]);
	if (game->sprites.bg[1])
		mlx_destroy_image(game->mlx, game->sprites.bg[1]);
	if (game->sprites.bg[2])
		mlx_destroy_image(game->mlx, game->sprites.bg[2]);
	if (game->sprites.bg[3])
		mlx_destroy_image(game->mlx, game->sprites.bg[3]);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.coins[0])
		mlx_destroy_image(game->mlx, game->sprites.coins[0]);
	if (game->sprites.coins[1])
		mlx_destroy_image(game->mlx, game->sprites.coins[1]);
	if (game->sprites.coins[2])
		mlx_destroy_image(game->mlx, game->sprites.coins[2]);
	if (game->sprites.enemy)
		mlx_destroy_image(game->mlx, game->sprites.enemy);
}

/**
 * Function: Free game
 * -----------------
 * This functions frees the memory allocated for the game struct, being the
 * sprites, the window, the display, the objects and the map. It also exits the
 * program. Free game is called by the close_window function when the user
 * presses the ESC key or closes the window.
 * 
 * @param: *map
 *
 * @return: Is a void function.
 *
 */

void	free_game(t_game *game)
{
	free_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	cleanup_objects(&game->objects);
	free_map(&game->map);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}
