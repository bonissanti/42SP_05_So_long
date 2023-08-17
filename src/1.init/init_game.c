/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:39:11 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:01:47 by brunrodr         ###   ########.fr       */
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
}

