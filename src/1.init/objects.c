/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:59:46 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 15:20:49 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: int objects
 * -----------------
 * This is a function that will initialize the objects of the game. It will
 * allocate memory for the objects, according to the number of objects in the
 * map. And will call the check_object function for each object.
 *
 * @param: *game - Pointer to the game struct.
 * @param: **objects - Double pointer to the objects struct.
 * @param: *num_obj - Pointer to the number of objects in the map.
 * @param: max_obj - Maximum number of objects in the map.
 *
 * @return: Is a void function.
 *
 */

void	init_objects(t_game *game, t_object **objects, int *num_obj,
		int max_obj)
{
	*num_obj = 0;
	max_obj = game->map.rows * game->map.columns;
	allocate_objects(objects, max_obj);
	check_object(game, objects, num_obj, 'C');
	check_object(game, objects, num_obj, 'E');
	check_object(game, objects, num_obj, 'X');
}

/**
 * Function: Allocate objects
 * -----------------
 * This is a function that will allocate memory for the objects of the game.
 * It will allocate memory for the objects, according to the number of objects
 * in the map, resulting in a maximum of rows * columns objects. After that, it
 * will initialize the objects, setting the symbol to 0, the x and y to 0, the
 * sprite to NULL and the is_collected to false.
 *
 * @param: **objects - Double pointer to the objects struct.
 * @param: max_obj - Maximum number of objects in the map.
 *
 * @return: Is a void function.
 *
 */

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

/**
 * Function: Find objects
 * -----------------
 * This is a function that will find the objects of the game. It will iterate
 * through the map, and for each object it will set the symbol, the x and y
 * coordinates of the object, and increment the number of objects.
 *
 * @param: **objects - Double pointer to the objects struct.
 * @param: num_obj - Pointer to the number of objects in the map.
 * @param: symbol - The symbol of the object.
 *
 * @return: Is a void function.
 *
 */

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

/**
 * Function: Check object
 * -----------------
 * This is a function that will check if the object exists in the map. It will
 * call the find_objects function, and if it returns false, it will print an
 * error message and exit the program.
 * 
 * @param: *game - Pointer to the game struct.
 * @param: **objects - Double pointer to the objects struct.
 * @param: *num_obj - Pointer to the number of objects in the map.
 * @param: symbol - The symbol of the object.
 *
 * @return: Is a void function.
 *
 */

void	check_object(t_game *game, t_object **objects, int *num_obj,
		char symbol)
{
	if (!find_objects(game, objects, num_obj, symbol))
	{
		ft_printf("Error\nFailed to find %c\n", symbol);
		exit(1);
	}
}
