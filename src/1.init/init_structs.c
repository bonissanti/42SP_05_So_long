/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:40:40 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map_defaults(t_game *game);
void	init_sprites_defaults(t_sprites *sprites);
void	init_player_defaults(t_player *player, t_sprites *sprites);

void	init_map_defaults(t_game *game)
{
	int	i;

	game->map.rows = 0;
	game->map.columns = 0;
	game->map.matriz = NULL;
	game->map.pos_x = 0;
	game->map.pos_y = 0;
	game->map.moves = 0;
	game->frame_counter = 0;
	game->frame_bg = 0;
	game->frame_mario_l = 0;
	game->frame_mario_r = 0;
	game->frame_mario_u = 0;
	game->frame_mario_d = 0;
	game->current_coins = 0;
	game->current_bg = 0;
	game->current_mario_l = 0;
	game->current_mario_r = 0;
	game->current_mario_u = 0;
	game->current_mario_d = 0;
	i = -1;
	while (++i < 5)
		object_set(&game->object[i], 0, 0, 0, 0);
}

void	init_player_defaults(t_player *player, t_sprites *sprites)
{
	player->x = 0;
	player->y = 0;
	player->direction_x = 0;
	player->direction_y = 0;
	sprites->mario_l[0] = NULL;
	sprites->mario_l[1] = NULL;
	sprites->mario_l[2] = NULL;
	sprites->mario_r[0] = NULL;
	sprites->mario_r[1] = NULL;
	sprites->mario_r[2] = NULL;
	sprites->mario_u[0] = NULL;
	sprites->mario_u[1] = NULL;
	sprites->mario_u[2] = NULL;
	sprites->mario_d[0] = NULL;
	sprites->mario_d[1] = NULL;
	sprites->mario_d[2] = NULL;
}

void	init_sprites_defaults(t_sprites *sprites)
{
	sprites->bg[0] = NULL;
	sprites->bg[1] = NULL;
	sprites->bg[2] = NULL;
	sprites->bg[3] = NULL;
	sprites->wall = NULL;
	sprites->coins[0] = NULL;
	sprites->coins[1] = NULL;
	sprites->coins[2] = NULL;
	sprites->exit = NULL;
}

