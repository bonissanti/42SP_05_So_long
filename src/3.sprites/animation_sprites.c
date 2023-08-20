<<<<<<< HEAD
#include "../so_long.h"

int		no_event(t_game *game);
void	mlx_hooks(t_game *game);

int	no_event(t_game *game)
{
	(void)game;
	return (1);
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:02:25 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:31:37 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_hooks(t_game *game);
int	    animation_loop(t_game *game);

int	animation_loop(t_game *game)
{
	if (game->frame_counter % 15 == 0)
		game->current_coins = (game->current_coins + 1) % 3;
	game->frame_counter++;
	if (game->frame_bg % 15 == 0)
		game->current_bg = (game->current_bg + 1) % 1;
	game->frame_bg++;
	if (game->frame_mario_l % 15 == 0)
		game->current_mario_l = (game->current_mario_l + 1) % 3;
	game->frame_mario_l++;
	if (game->frame_mario_r % 15 == 0)
		game->current_mario_r = (game->current_mario_r + 1) % 3;
	game->frame_mario_r++;
	if (game->frame_mario_u % 15 == 0)
		game->current_mario_u = (game->current_mario_u + 1) % 3;
	game->frame_mario_u++;
	if (game->frame_mario_d % 15 == 0)
		game->current_mario_d = (game->current_mario_d + 1) % 3;
	game->frame_mario_d++;
	draw_game(game, &game->map);
	return (0);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}

void	mlx_hooks(t_game *game)
{
<<<<<<< HEAD
	mlx_loop_hook(game->mlx, &no_event, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}
=======
	mlx_loop_hook(game->mlx, &animation_loop, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
