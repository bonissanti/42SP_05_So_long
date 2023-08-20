#include "../so_long.h"

void	init_objects(t_game *game, t_object **objects, int *num_obj,
		int max_obj)
{
	*num_obj = 0;
	max_obj = game->map.rows * game->map.columns;
	allocate_objects(objects, max_obj);
	*num_obj = 0;
	check_object(game, objects, num_obj, 'C');
	check_object(game, objects, num_obj, 'E');
	check_object(game, objects, num_obj, 'X');
}

void	allocate_objects(t_object **objects, int max_obj)
{
	int	i;

	i = 0;
	*objects = malloc(sizeof(t_object) * max_obj);
	if (!*objects)
	{
		ft_printf("Error\nFailed to allocate memory for objects\n");
		exit(1);
	}
	while (i < max_obj)
	{
		(*objects)[i].symbol = 0;
		(*objects)[i].x = 0;
		(*objects)[i].y = 0;
		(*objects)[i].sprite = NULL;
		(*objects)[i].is_collected = is_false;
		i++;
	}
}

int	find_objects(t_game *game, t_object **objects, int *num_obj, char symbol)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.rows)
	{
		col = 0;
		while (col < game->map.columns)
		{
			if (game->map.matriz[row][col] == symbol)
			{
				(*objects)[*num_obj].symbol = symbol;
				(*objects)[*num_obj].x = col;
				(*objects)[*num_obj].y = row;
				(*num_obj)++;
			}
			col++;
		}
		row++;
	}
	if (*num_obj == 0)
		return (0);
	return (1);
}

void	check_object(t_game *game, t_object **objects, int *num_obj,
		char symbol)
{
	if (!find_objects(game, objects, num_obj, symbol))
	{
		ft_printf("Error\nFailed to find %c\n", symbol);
		exit(1);
	}
}
