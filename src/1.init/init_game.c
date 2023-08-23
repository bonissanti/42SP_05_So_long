/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:59:52 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 13:07:22 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: init_structs
 * -----------------
 * Initializes all the structs with default values. This is important because
 * if we don't initialize the values, they will be random and we will have
 * problems with the program.
 *
 * @param: game -  A pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	init_structs(t_game *game);
void	init_game(t_game *game);

void	init_structs(t_game *game)
{
	init_map_defaults(game);
	init_sprites_defaults(&game->sprites);
	init_player_defaults(&game->player, &game->sprites);
}

/**
 * Function: init_game
 * -----------------
 * This function initializes the game using two pointers. One to the mlx_init, that's the 
 * function to start the mlx, and the other one is the mlx_new_window, that's the function
 * to create a new window. If any of those functions returns NULL, it will print an error
 * message and exit the program.
 * 
 * @param: game -  A pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initializing mlx\n");
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->window)
	{
		ft_printf("Error creating window\n");
		free(game->mlx);
		exit(1);
	}
}
