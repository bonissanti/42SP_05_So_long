/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:35:38 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/27 19:05:27 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"
#include "../../../my_libft/src/ft_strlen.c"

//Algorithm 'flood fill' to check if the 'P' is able to reach the 'E' in the map

int flood_fill(char **map, int x, int y, char target, char replace)
{
	if (x < 0 || x >= ft_strlen(map[0]) || y < 0 || y >= ft_strlen(map[0]))
		return (0);
	if (map[x][y] != target)
		return (0);
	map[x][y] = replace;
	flood_fill(map, x + 1, y, target, replace);
	flood_fill(map, x - 1, y, target, replace);
	flood_fill(map, x, y + 1, target, replace);
	flood_fill(map, x, y - 1, target, replace);
	return (1);
} 

int main(void)
{
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
			"10000000000000000001",
			"10000000000000000001",
			"11111111111111111111",
			NULL
	};

	int x = 5;
	int y = 12;
	char target = 'E';
	char replace = 'P';
	
	flood_fill(zone, x, y, target, replace);

	int i = 0;
	while (zone[i])
	{
		printf("%s\n", zone[i]);
		i++;
	}

	if (zone[x][y] == 'E')
		printf("Map is valid\n");
	else
		printf("Map is not valid\n");
		
	return (0);	
}