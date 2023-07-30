/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:13:48 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/27 15:33:53 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"
#include "../../../my_libft/src/ft_strlen.c"

//Function to check size map file and return 1 if is valid or 0 if is not valid

int	check_size(t_map *map)
{
	int rows;
	int columns;

	rows = 0;
	while (map->matriz[rows])
	{
		columns = ft_strlen(map->matriz[rows]);
		if (rows == 0)
			map->columns = columns;
		else if (map->columns != columns)
			return (0);
		rows++;	
	}
	map->rows = rows;
	return (1);
}



int main(void)
{
	t_map matriz_size;
	
	char *zone[] = {
			"11111111111111111111",
			"100000000E0000000001",
			"10000000000000000001",
			"10000000000000000001",
			"10000000000000000001",
			"100000C00001P0000001",
			"10000000000000000001",
			"10000000000000000001",
			"100000000C0000000001",
			"10000000000000000001",
			"10000000000000000001",
			"11111111111111111111",
			NULL
	};

	matriz_size.matriz = zone;

	if (check_size(&matriz_size) == 1)
		printf("Map is valid\n");
	else
		printf("Map is not valid\n");
	return (0);
}


// printf("Invalid row %d: previous columns count was %d, this row's columns count is %d\n", rows, map->columns, columns);



// {
// 	int	rows;
// 	int columns;
// 	char **map_matriz;

// 	rows = 0;
// 	while (map->map_matriz[rows])
// 	{
// 		columns = 0;
// 		while (map->map_matriz[rows][columns])
// 			columns++;
// 		if (rows == 0)
// 			map->columns = columns;
// 		else if (map->columns != columns)
// 			return (0);
// 		rows++;
// 	}	
// 	map->rows = rows;
// 	return (1);
// }