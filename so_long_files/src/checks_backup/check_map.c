/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:33 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/27 15:39:29 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../../../my_libft/src/ft_strlen.c"
#include "../../../my_libft/src/ft_strdup.c"

#include "../include/so_long.h"

void initialize_map(t_map *map, int rows, int columns, char **map_matriz)
{
	map->moves = 0;
	map->matriz = map_matriz;
	map->file = NULL;
	map->rows = rows;
	map->columns = columns;
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	map->empty = 0;
	map->wall = 0;
}

int	is_valid_map(t_map *map)
{
	int		col;
	int		row;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			if ((row == 0 || row == map->rows - 1 || col == 0 || col == map->columns - 1) && map->matriz[row][col] != '1')
				return (0);
			
			if (map->matriz[row][col] != '0' && map->matriz[row][col] != '1' && map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E' && map->matriz[row][col] != 'P')
				return (0);
			else if (map->matriz[row][col] == 'P')
				map->player++;
			else if (map->matriz[row][col] == 'C')
				map->collectible++;
			else if (map->matriz[row][col] == 'E')
				map->exit++;
			else if (map->matriz[row][col] == '0')
				map->empty++;
			else if (map->matriz[row][col] == '1')
				map->wall++;
			else
				return (0);
			col++;
		}
		row++;
	}
	if (map->player != 1)
		return (0);
	if (map->collectible < 1)
		return (0);
	if (map->exit < 1)
		return (0);
	return (1);
}	

int main(void)
{
	t_map	matriz_size;

	char *zone[] = {
			"11111111111111111111",
			"100000000E0000000001",
			"10000000000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"100000C00000P0000001",
			"10000000000000000001",
			"10000000000000000001",
			"100000000C0000000001",
			"11111111111111111111",
			"10000000000000000001",
			"11111111111111111111"
	};

	matriz_size.matriz = zone;

	initialize_map(&matriz_size, 12, 20, zone);	
	int result = is_valid_map(&matriz_size);
	if(result == 1)
		printf("O mapa é válido\n");
	else
		printf("O mapa é inválido\n");
	return (0);
}


// else if (map->map_matriz[row][col] != '0' && map->map_matriz[row][col] != '1' && map->map_matriz[row][col] != 'C' && map->map_matriz[row][col] != 'E' && map->map_matriz[row][col] != 'P')
// 				return (0);
// 			else if (map->map_matriz[row][col] == 'P')
// 				map->player++;
// 			else if (map->map_matriz[row][col] == 'C')
// 				map->collectible++;
// 			else if (map->map_matriz[row][col] == 'E')
// 				map->exit++;
// 			else if (map->map_matriz[row][col] == '0')
// 				map->empty++;
// 			else if (map->map_matriz[row][col] == '1')
// 				map->wall++;
// 			else
// 				return (0);