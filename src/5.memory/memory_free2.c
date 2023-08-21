/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:00:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 11:00:19 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	cleanup_objects(t_object **objects)
{
	free(*objects);
	*objects = NULL;
}
