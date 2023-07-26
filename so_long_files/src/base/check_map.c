/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:07:33 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/26 18:30:44 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_libft/include/libft.h"
#include "../../../my_libft/src/ft_strlen.c"
#include "../../../my_libft/src/ft_strdup.c"

#include "../../include/so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;


t_point	find_char(t_map *map, char c)
{
	t_point	point;
	char	**row;
	char	*col;

	row = map->map_chars;
	point.y = 0;
	while (row < map->map_chars + map->rows)
	{
		col = *row;
		point.x = 0;
		while (col < *row + map->columns)
		{
			if (*col == c)
				return (point);
			col++;
			point.x++;
		}
		row++;
	}
	return (point){-1, -1};
}


int	is_valid_map(t_map *map)
{
	char	**row;
	char	*col;

	row = map->map_chars;
	while (row < map->map_chars + map->rows)
	{
		col = *row;
		while (col < *row + map->columns)
		{
			if ((row == map->map_chars || row == map->map_chars + map->rows - 1
				|| col == *row) ||( col == *row + map->columns - 1 && *col != '1'))
				return (0);
			else if (*col != '0' && *col != '1' && *col != 'C' && *col != 'E'
				&& *col != 'P')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}


int	main() {
    t_map map;
    FILE* file;
    char columns[20]; // Ajuste o tamanho de acordo com o maior número de colunas no mapa
    int row_count = 0;
    int i;

    // Ajuste o tamanho de acordo com o maior número de linhas no mapa
    map.map_chars = (char**)malloc(12 * sizeof(char*));
	
    if (map.map_chars == NULL) {
        printf("Failed to allocate memory for map\n");
        return -1;
    }
	
    file = fopen("map-test.ber", "r");
	
    if(file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while(fgets(columns, sizeof(columns), file)) {
		// Ajuste o tamanho de acordo com o maior número de colunas no mapa
        map.map_chars[row_count] = (char*)malloc(20 * sizeof(char));
		
        if (map.map_chars[row_count] == NULL) {
            printf("Failed to allocate memory for row\n");
            return -1;
        }

        i = 0;
        while(columns[i] != '\n' && i < 20) {
            map.map_chars[row_count][i] = columns[i];
            i++;
        }
        row_count++;

        if(row_count == 12) {
            break;
        }
    }
	
    fclose(file);

    map.rows = row_count;
    map.columns = 20; // Ajuste o tamanho de acordo com o maior número de colunas no mapa

    int result = is_valid_map(&map);
    if(result == 1){
        printf("O mapa é válido\n");
    } else {
        printf("O mapa é inválido\n");
    }

    i = 0;
    while(i < map.rows) {
        free(map.map_chars[i]);
        i++;
    }

    free(map.map_chars);

    return 0;
}