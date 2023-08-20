#include "../so_long.h"

int		no_event(t_game *game);
void	mlx_hooks(t_game *game);

int	no_event(t_game *game)
{
	(void)game;
	return (1);
}

void	mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &no_event, game);
	mlx_hook(game->window, 2, 1L << 0, &key_press, game);
	mlx_hook(game->window, 17, 1L << 17, &close_window, game);
	mlx_loop(game->mlx);
}
