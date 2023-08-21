/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:27 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 11:57:18 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		no_event(t_game *game);
void	mlx_hooks(t_game *game);

int	no_event(t_game *game)
{
	(void)game;
	print_steps_to_screen(game);
	return (1);
}

void	mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &no_event, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}
