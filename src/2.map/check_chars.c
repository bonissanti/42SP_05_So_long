/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:50:48 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 13:54:50 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: Count coins
 * -----------------
 * This is a function that will count the number of coins in the map.
 * It will count the number of coins in the map, according to the number of
 * objects in the map.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: Is a void function.
 *
 */

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

/**
 * Function: Valid char
 * -----------------
 * This is a function that will validate the characters in the map.
 * Will be considered valid characters: 0, 1, C, E, P, X and \n.
 * If the map has any other character, the program will exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: The function will return 1 if the map has valid characters. 
 *
 */

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
				ft_printf("Error\nMap must have valid characters\n");
				free_map(map);
				exit(1);
			}
			col++;
		}
		row++;
	}
	return (1);
}
