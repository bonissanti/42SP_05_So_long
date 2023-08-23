/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:00:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/23 10:52:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: Cleanup and exit
 * -----------------
 * This functions is the final function of the flood fill algorithm. It will
 * free the matriz visited and the map, and will exit the program with an error
 * message, if the flag is 1. If the flag is 0, it will only free the matriz visited 
 * and the map.
 * 
 * @param: *map - Pointer to the map struct.
 * @param: flag - Flag to check if the program will exit with an error message.
 *
 * @return: Is a void function.
 *
 */

int	cleanup_and_exit(t_map *map, int flag)
{
	int	row;

	row = 0;
	if (flag == 1)
	{
		ft_printf("Error\nMap must have a path from P to all C and E\n");
		while (row < map->rows)
		{
			free(map->visited[row]);
			row++;
		}
		free(map->visited);
		free_map(map);
		exit(1);
	}
	else
	{
		while (row < map->rows)
		{
			free(map->visited[row]);
			row++;
		}
		free(map->visited);
		return (0);
	}
}

/**
 * Function: Cleanup objects
 * -----------------
 * This functions frees the objects struct.
 * 
 * @param: **objects - Pointer to the objects struct.
 *
 * @return: Is a void function.
 *
 */

void	cleanup_objects(t_object **objects)
{
	free(*objects);
	*objects = NULL;
}
