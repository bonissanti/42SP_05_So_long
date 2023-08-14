#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

int	key_press(int keycode, t_game *game);
int	check_next_position(int next_x, int next_y, t_game *game);
int won_or_lost(t_game *game, char next_pos);

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
	}
	draw_game(game, &game->map);
	return (0);
}

int	check_next_position(int next_x, int next_y, t_game *game)
{
	char	next_pos;

	if (next_x < 0 || next_x >= game->map.columns * SPRITE_SIZE || next_y < 0
		|| next_y >= game->map.rows * SPRITE_SIZE)
		return (0);
	next_pos = game->map.matriz[next_y / SPRITE_SIZE][next_x / SPRITE_SIZE];
	if (next_pos == '1')
	{
		printf("You hit a wall!\n");
		return (0);
	}
	else if (next_pos == 'C')
	{
		game->map.c_count--;
		game->map.matriz[next_y / SPRITE_SIZE][next_x / SPRITE_SIZE] = '0';
	}
	else 
		return (won_or_lost(game, next_pos));
	return (1);
}

int won_or_lost(t_game *game, char next_pos)
{
	if (next_pos == 'E')
	{
		if (game->map.c_count == 0)
		{
			printf("You win!\n");
			free_game(game);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("You must collect all coins first!\n");
			return (0);
		}
	}
	else if (next_pos == 'X')
	{
		printf("You hit an enemy! Game over.\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}