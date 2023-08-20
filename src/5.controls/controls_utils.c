<<<<<<<< HEAD:src/4.controls/controls_utils.c
========
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:03:02 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:03:04 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4:src/5.controls/controls_utils.c
#include "../so_long.h"

int		key_press(int keycode, t_game *game);
int		check_next_position(int next_x, int next_y, t_game *game);
int		won_or_lost(t_game *game, char next_pos);
void	mark_as_collected(t_object **objects, int num_obj, int next_x,
			int next_y);

int	key_press(int keycode, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->object->x;
	next_y = game->object->y;
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		l_key(&next_x, &game->player.direction_x, &game->player.direction_y);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		r_key(&next_x, &game->player.direction_x, &game->player.direction_y);
	else if (keycode == KEY_W || keycode == KEY_UP)
		u_key(&next_y, &game->player.direction_x, &game->player.direction_y);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		d_key(&next_y, &game->player.direction_x, &game->player.direction_y);
	if (check_next_position(next_x, next_y, game))
	{
<<<<<<<< HEAD:src/4.controls/controls_utils.c
		game->player.x = next_x;
		game->player.y = next_y;
		animate_sprites(game);
========
		game->object->x = next_x;
		game->object->y = next_y;
>>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4:src/5.controls/controls_utils.c
	}
	draw_game(game, &game->map, game->objects, game->num_obj);
	return (0);
}

int	check_next_position(int next_x, int next_y, t_game *game)
{
	char	next_pos;

	if (next_x < 0 || next_x >= game->map.columns * SPRITE_SIZE || next_y < 0
		|| next_y >= game->map.rows * SPRITE_SIZE)
		return (0);
	game->map.moves += 1;
	ft_printf("Moves: %d\n", game->map.moves);
	next_pos = game->map.matriz[next_y / SPRITE_SIZE][next_x / SPRITE_SIZE];
	if (next_pos == '1')
	{
		ft_printf("You hit a wall!\n");
		return (0);
	}
	else if (next_pos == 'C')
	{
		game->map.c_count--;
		game->map.matriz[next_y / SPRITE_SIZE][next_x / SPRITE_SIZE] = '0';
		mark_as_collected(&game->objects, game->num_obj, next_x / SPRITE_SIZE,
			next_y / SPRITE_SIZE);
	}
	else
		return (won_or_lost(game, next_pos));
	return (1);
}

int	won_or_lost(t_game *game, char next_pos)
{
	if (next_pos == 'E')
	{
		if (game->map.c_count == 0)
		{
			ft_printf("You win!\n");
			free_game(game);
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_printf("You must collect all coins first!\n");
			return (0);
		}
	}
	else if (next_pos == 'X')
	{
		ft_printf("You hit an enemy! Game over.\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	return (1);
}

void	mark_as_collected(t_object **objects, int num_obj, int next_x,
		int next_y)
{
	int	i;

	i = 0;
	while (i < num_obj)
	{
		if ((*objects)[i].x == next_x && (*objects)[i].y == next_y
			&& (*objects)[i].symbol == 'C')
		{
			(*objects)[i].is_collected = is_true;
			return ;
		}
		i++;
	}
}
