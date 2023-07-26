/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:09:07 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/26 14:02:55 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../../my_libft/include/libft.h"

// Fuction to check if the map file is .ber

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

// Fuction to check if the map file is valid

int is_valid_map(t_map *map)
{
	char **row = map->map_chars;
	char *col;

	while (row < map->map_chars + map->rows)
	{
		col = *row;
		while (col < *row + map->cols)
		{
			
		}
	}
	
	
	
}

