/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:14 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 12:08:54 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	next_x = game->player.x;
	next_y = game->player.y;
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
		game->player.x = next_x;
		game->player.y = next_y;
		animate_sprites(game);
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

void	print_steps_to_screen(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->map.moves);
	mlx_string_put(game->mlx, game->window, 20, 20, 0x00000000,
		steps);
	free(steps);
}
