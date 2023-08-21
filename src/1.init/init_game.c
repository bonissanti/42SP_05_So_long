/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:59:52 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 10:59:53 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_structs(t_game *game);
void	init_game(t_game *game);

void	init_structs(t_game *game)
{
	init_map_defaults(game);
	init_sprites_defaults(&game->sprites);
	init_player_defaults(&game->player, &game->sprites);
}

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
