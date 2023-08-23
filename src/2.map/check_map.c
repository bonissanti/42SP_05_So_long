/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:50:53 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 14:26:21 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: Check size
 * -----------------
 * This is a function that will check if the map is rectangular.
 * It will check if the map is rectangular, comparing the number of columns of
 * each row. If the map is not rectangular, the program will exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: This function will return 1 if the map is rectangular.
 *
 */

int	check_size(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->matriz[row][col] != '\0')
			col++;
		if (col != map->columns)
		{
			ft_printf("Error\nMap must be rectangular\n");
			free_map(map);
			exit(1);
		}
		row++;
	}
	return (1);
}

/**
 * Function: Check wall
 * -----------------
 * This is a function that will check if the map has walls, 
 * comparing the first and last row and column of the map.
 * If the map doesn't have walls, the program will exit with an error. 
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: This function will return 1 if the map has walls.
 *
 */

int	check_wall(t_map *map)
{
	int		row;
	size_t	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < ft_strlen(map->matriz[row]))
		{
			if (map->matriz[row][col] == '\n')
			{
				col++;
				continue ;
			}
			if ((row == 0 || row == map->rows - 1 || col == 0
					|| col == ft_strlen(map->matriz[row]) - 1))
			{
				if (map->matriz[row][col] != '1')
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

/**
 * Function: Check players
 * -----------------
 * This is a function that will check if the map has one player.
 * If the map doesn't have players or has more than one player, the program will
 * exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: This is a void function.
 *
 */

void	check_players(t_map *map)
{
	int	row;
	int	col;
	int	player_count;

	row = 0;
	player_count = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->matriz[row][col])
		{
			if (map->matriz[row][col] == 'P')
				player_count++;
			col++;
		}
		row++;
	}
	if (player_count != 1)
	{
		ft_printf("Error\nMap must have only one player\n");
		free_map(map);
		exit(1);
	}
}

/**
 * Function: Check exit
 * -----------------
 * This is a function that will check if the map has one exit.
 * If the map doesn't have exits or has more than one exit, the program will
 * exit with an error.
 * 
 * @param: *map - Pointer to the map struct.
 *
 * @return: This is a void function.
 *
 */

void	check_exit(t_map *map)
{
	int	row;
	int	col;
	int	exit_count;

	row = 0;
	exit_count = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->matriz[row][col])
		{
			if (map->matriz[row][col] == 'E')
				exit_count++;
			col++;
		}
		row++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error\nMap must have only one exit\n");
		free_map(map);
		exit(1);
	}
}
