/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:02:09 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:10 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_coins(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	map->coins = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == 'C')
				map->coins++;
			col++;
		}
		row++;
	}
}

int	valid_char(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] != '0' && map->matriz[row][col] != '1'
				&& map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E'
				&& map->matriz[row][col] != 'P' && map->matriz[row][col] != 'X'
				&& map->matriz[row][col] != '\n')
			{
				printf("Error\nMap must have valid characters\n");
				free_map(map);
				exit(1);
			}
			col++;
		}
		row++;
	}
	return (1);
}
