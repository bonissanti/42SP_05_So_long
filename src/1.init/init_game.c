<<<<<<< HEAD
=======
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

>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
#include "../so_long.h"

void	init_structs(t_game *game);
void	init_game(t_game *game);

void	init_structs(t_game *game)
{
	init_map_defaults(game);
	init_sprites_defaults(&game->sprites);
	init_player_defaults(&game->player, &game->sprites);
}

<<<<<<< HEAD
=======

>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
<<<<<<< HEAD
		ft_printf("Error initializing mlx\n");
=======
		printf("Error initializing mlx\n");
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
		exit(1);
	}
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->window)
	{
<<<<<<< HEAD
		ft_printf("Error creating window\n");
		free(game->mlx);
		exit(1);
	}
}
=======
		printf("Error creating window\n");
		free(game->mlx);
		exit(1);
	}
	game->buffer = create_buffer(game->mlx, WIN_WIDTH, WIN_HEIGHT);
}

>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
