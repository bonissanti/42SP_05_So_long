/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 15:01:03 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		no_event(t_game *game);
void	mlx_hooks(t_game *game);

/**
 * Function: No event
 * -----------------
 * This is a function no event. In a nutshell, this function is a loop for
 * the mlx_loop_hook function and do nothing. It's used to looping the game
 * avoiding the game to blink
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

int	no_event(t_game *game)
{
	(void)game;
	print_steps_to_screen(game);
	return (1);
}

/**
 * Function: Mlx hooks
 * -----------------
 * This is a function that calls the mlx_loop_hook function and the mlx_hook
 * function. The mlx_loop_hook function is used to looping the game, mlx_hook
 * function is used to handle the events, like key press and close window.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

void	mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &no_event, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}
