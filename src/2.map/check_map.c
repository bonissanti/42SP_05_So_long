/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:02:15 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:16 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_size(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->matriz[row][col] != '\0')
			col++;
		if (col != map->columns)
		{
			printf("Error\nMap must be rectangular\n");
			free_map(map);
			exit(1);
		}
		row++;
	}
	return (1);
}

int	check_wall(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if (map->matriz[row][col] == '\n')
			{
				col++;
				continue ;
			}
			if ((row == 0 || row == map->rows - 1 || col == 0
					|| col == map->columns - 1))
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

void check_players(t_map *map)
{
    int row;
    int col;
    int player_count;

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
		printf("Error\nMap must have only one player\n");
		free_map(map);
		exit(1);
	}
}

void check_exit(t_map *map)
{
	int row;
	int col;
	int exit_count;

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
		printf("Error\nMap must have only one exit\n");
		free_map(map);
		exit(1);
	}
}
