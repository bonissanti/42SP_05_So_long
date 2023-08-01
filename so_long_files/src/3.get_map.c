#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"
#include "../../my_libft/src/get_next_line.c"
#include "../../my_libft/src/get_next_line_utils.c"
#include "../../my_libft/src/ft_strlen.c"

// int count_lines(t_map *map)
// {
//     int fd;
//     char buffer[4096];
//     int bytes_read;
//     int line_count;
//     int i;

//     fd = open(map->file, O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     line_count = 0;
//     while ((bytes_read = read(fd, buffer, 4096)))
//     {
//         i = 0;
//         while (i < bytes_read)
//         {
//             if (buffer[i] == '\n' || buffer[i] == '\0')
//                 line_count++;
//             i++;
//         }
//     }
//     close(fd);
//     return (line_count);
// }

void get_map(t_map *map)
{
    int i;
    int fd;
    char *line;

    i = 0;
    map->rows = 0;
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line || line[0] == '\0')
            break;
        map->rows++;
        free(line);
    }

    close(fd);
    map->matriz = malloc(sizeof(char *) * (map->rows));

    if (!map->matriz)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    fd = open(map->file, O_RDONLY);
    while (i < map->rows)
    {
        map->matriz[i] = get_next_line(fd);
        i++;

    }
    close(fd);


}

// Function to check size of map
int	check_size(t_map *map)
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
                continue;
            }
            if (map->matriz[row][col] != '1' && map->matriz[row][col] != '0' && map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E' && map->matriz[row][col] != 'P')
            {
                printf("Error: Invalid character\n");
                return (0);
            }
            col++;
        }
        row++;
    }
    return (1);

}

int check_wall(t_map *map)
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
                continue;
            }
            if ((row == 0 || row == map->rows - 1 || col == 0 || col == map->columns - 1))
            {
                if (map->matriz[row][col] != '1')
                {
                    printf("Last row: %d\n", map->rows - 1);
                    return (0);
                }
            }
            col++;
        }
        row++;
    }
    return (1); 
}


int main(void)
{
    t_map *map;
    int i;

    map = malloc(sizeof(t_map));
    if (!map)
    {
        printf("Error allocating memory\n");
        return (1);
    }
    map->file = "map-test.ber";
    get_map(map);

    if (!check_size(map))
    {
        printf("Error: Invalid map size\n");
        return (1);
    }
    if (!check_wall(map))
    {
        printf("Error: Invalid map wall\n");
        return (1);
    }
    i = 0;
    while (i < map->rows)
    {
        printf("%s", map->matriz[i]);
        i++;
    }
    while (i < map->rows)
    {
        free(map->matriz[i]);
        i++;
    }
    free(map);
    
}



// int	is_valid_map(t_map *map)
// {
// 	int		col;
// 	int		row;

// 	row = 0;
// 	while (row < map->rows)
// 	{
// 		col = 0;
// 		while (col < map->columns)
// 		{
// 			if ((row == 0 || row == map->rows - 1 || col == 0 || col == map->columns - 1) && map->matriz[row][col] != '1')
// 				return (0);
			
// 			if (map->matriz[row][col] != '0' && map->matriz[row][col] != '1' && map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E' && map->matriz[row][col] != 'P')
//             {
//                 if (map->matriz[row][col] == '\0')
//                     continue;
//                 else
//                     return (0);
//             }
// 			else if (map->matriz[row][col] == 'P')
// 				map->player++;
// 			else if (map->matriz[row][col] == 'C')
// 				map->collectible++;
// 			else if (map->matriz[row][col] == 'E')
// 				map->exit++;
// 			else if (map->matriz[row][col] == '0')
// 				map->empty++;
// 			else if (map->matriz[row][col] == '1')
// 				map->wall++;
// 			else
// 				return (0);
// 			col++;
// 		}
// 		row++;
// 	}
// 	if (map->player != 1)
// 		return (0);
// 	if (map->collectible < 1)
// 		return (0);
// 	if (map->exit < 1)
// 		return (0);
// 	return (1);
// }	