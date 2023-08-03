// #include "../include/so_long.h"
// #include "../../my_libft/include/libft.h"
// #include "../../my_libft/src/get_next_line.c"
// #include "../../my_libft/src/get_next_line_utils.c"
// #include "../../my_libft/src/ft_strlen.c"


// int count_lines(t_map *map) //Function ok
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

// void get_map(t_map *map) //Function ok
// {
//     int fd;
//     char *line;
//     int i;

//     map->rows = count_lines(map);
//     map->matriz = malloc(sizeof(char *) * (map->rows));
//     if (!map->matriz)
//     {
//         printf("Error allocating memory\n");
//         exit(1);
//     }
//     fd = open(map->file, O_RDONLY);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }
//     i = 0;
//     while (i < map->rows)
//     {
//         map->matriz[i] = get_next_line(fd);
//         i++;
//     }
//     map->columns = ft_strlen(map->matriz[0]);
//     close (fd);
// }

// // Function to check size of map
// int check_size(t_map *map) // Function ok
// {
//     int row;
//     int col;

//     row = 0;
//     while (row < map->rows)
//     {
//         col = 0;
//         while (map->matriz[row][col] != '\0')
//             col++;
//         if (col != map->columns)
//             return (0);
//         row++;
//     }
//     return (1);
// }

// int check_wall(t_map *map) // Function ok
// {
//     int row;
//     int col;

//     row = 0;
//     while (row < map->rows)
//     {
//         col = 0;
//         while (col < map->columns)
//         {
//             if (map->matriz[row][col] == '\n')
//             {
//                 col++;
//                 continue;
//             }
//             if ((row == 0 || row == map->rows - 1 || col == 0 || col == map->columns - 1))
//             {
//                 if (map->matriz[row][col] != '1')
//                     return (0);
//             }
//             col++;
//         }
//         row++;
//     }
//     return (1); 
// }

// t_player *find_player(t_map *map)
// {
//     int row;
//     int col;
//     t_player *player;

//     player = malloc(sizeof(t_player));
//     if (!player)
//     {
//         printf("Error allocating memory\n");
//         exit(1);
//     }
//     row = 0;
//     while (row < map->rows)
//     {
//         col = 0;
//         while (col < map->columns)
//         {
//             if (map->matriz[row][col] == 'P')
//             {
//                 player->x = col;
//                 player->y = row;
//                 return (player);
//             }
//             col++;
//         }
//         row++;
//     }
//     free(player);
//     return (NULL);
// }

// void	count_collectibles(t_map *map)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	map->collectible = 0;
// 	while (row < map->rows)
// 	{
// 		col = 0;
// 		while (col < map->columns)
// 		{
// 			if (map->matriz[row][col] == 'C')
// 				map->collectible++;
// 			col++;
// 		}
// 		row++;
// 	}
// }

// char	**copy_matriz(char **original, int rows, int columns)
// {
// 	char	**copy;
// 	int		x;
// 	int		y;

// 	x = 0;
// 	copy = (char **)malloc(sizeof(char *) * rows);
// 	if (!copy)
// 		return (NULL);
// 	while (x < rows)
// 	{
// 		copy[x] = (char *)malloc(sizeof(char) * columns);
// 		if (!copy[x])
// 			return (NULL);
// 		y = 0;
// 		while (y < columns)
// 		{
// 			copy[x][y] = original[x][y];
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (copy);
// }

// int	**visited_matriz(int rows, int columns)
// {
// 	int	**visited;
// 	int	x;
// 	int	y;

// 	x = 0;
// 	visited = (int **)malloc(sizeof(int *) * rows);
// 	if (!visited)
// 		return (NULL);
// 	while (x < rows)
// 	{
// 		visited[x] = (int *)malloc(sizeof(int) * columns);
// 		if (!visited[x])
// 			return (NULL);
// 		y = 0;
// 		while (y < columns)
// 		{
// 			visited[x][y] = 0;
// 			y++;
// 		}
// 		x++;
// 	}
// 	return (visited);
// }

// int flood_fill(t_map *map, int x, int y, char target, char replacement, int *count, int **visited)
// {
// 	char original;
// 	int result;
	
// 	if (x < 0 || x >= map->rows || y < 0 || y >= map->columns)
// 		return (0);

// 	if (visited[x][y])
// 		return (0);
	
// 	visited[x][y] = 1;

// 	if (map->matriz[x][y] == 'E')
// 	{
// 		if (*count < map->collectible)
// 			return (0);
// 		else
// 			return (1);
// 	}

// 	original = map->matriz[x][y];

// 	if (original == 'C')
// 		*count += 1;
	
// 	if (original == '1' || original == 'E' || original == 'X')
// 		return (0);

// 	map->matriz[x][y] = replacement;

// 	result = flood_fill(map, x + 1, y, target, replacement, count, visited) ||
// 			 flood_fill(map, x, y + 1, target, replacement, count, visited) ||
// 			 flood_fill(map, x - 1, y, target, replacement, count, visited) ||
// 			 flood_fill(map, x, y - 1, target, replacement, count, visited);


// 	map->matriz[x][y] = original;
// 	return (result);
// }

// void free_map(t_map *map)
// {
//     int i;

//     i = 0;
//     while (i < map->rows)
//     {
//         free(map->matriz[i]);
//         i++;
//     }
//     free(map->matriz);
//     free(map);
// }

// void print_map(t_game game)
// {
// 	int row;
// 	int col;

// 	row = 0;
// 	while (row < game.map.rows)
// 	{
// 		col = 0;
// 		while (col < game.map.columns)
// 		{
// 			printf("%c", game.map.matriz[row][col]);
// 			col++;
// 		}
// 		printf("\n");
// 		row++;
// 	}
// }

// int main(void)
// {
//     t_map *map;
//     char **copy;
//     int result;
//     int i;

//     map = malloc(sizeof(t_map));
//     if (!map)
//     {
//         printf("Error allocating memory\n");
//         return (1);
//     }
//     map->file = "map-test.ber";
//     get_map(map);

//     if (!check_size(map))
//     {
//         printf("Error: Invalid map size\n");
//         printf("Last row: %s", map->matriz[map->rows - 1]);
//         return (1);
//     }
//     if (!check_wall(map))
//     {
//         printf("Error: Invalid map wall\n");
//         return (1);
//     }

//     if (!find_player(map))
//     {
//         printf("Error: Invalid map\n");
//         return (1);
//     }
//     count_collectibles(map);
//     if (map->collectible < 1)
//     {
//         printf("Error coins: Invalid map\n");
//         return (1);
//     }
    
//     copy = copy_matriz(map->matriz, map->rows, map->columns);
//     if (!copy)
//     {
//         printf("Error: Failed to copy matriz\n");
//         return (1);
//     }
    
//     map->visited = visited_matriz(map->rows, map->columns);
//     if (!map->visited)
//     {
//         printf("Error: Failed to create visited matriz\n");
//         return (1);
//     }

//     if (flood_fill(map, map->player_y, map->player_x, '0', 'X', &map->count, map->visited))
//             printf("True: P can reach E and collect all C\n");
//         else
//             printf("False: P can't reach E or didn't collect all C\n");

//     i = 0;
//     while (i < map->rows)
//     {
//         printf("%s", map->matriz[i]);
//         i++;
//     }
//     free_map(map);
//     return (0);
// }



// // int	is_valid_map(t_map *map)
// // {
// // 	int		col;
// // 	int		row;

// // 	row = 0;
// // 	while (row < map->rows)
// // 	{
// // 		col = 0;
// // 		while (col < map->columns)
// // 		{
// // 			if ((row == 0 || row == map->rows - 1 || col == 0 || col == map->columns - 1) && map->matriz[row][col] != '1')
// // 				return (0);
			
// // 			if (map->matriz[row][col] != '0' && map->matriz[row][col] != '1' && map->matriz[row][col] != 'C' && map->matriz[row][col] != 'E' && map->matriz[row][col] != 'P')
// //             {
// //                 if (map->matriz[row][col] == '\0')
// //                     continue;
// //                 else
// //                     return (0);
// //             }
// // 			else if (map->matriz[row][col] == 'P')
// // 				map->player++;
// // 			else if (map->matriz[row][col] == 'C')
// // 				map->collectible++;
// // 			else if (map->matriz[row][col] == 'E')
// // 				map->exit++;
// // 			else if (map->matriz[row][col] == '0')
// // 				map->empty++;
// // 			else if (map->matriz[row][col] == '1')
// // 				map->wall++;
// // 			else
// // 				return (0);
// // 			col++;
// // 		}
// // 		row++;
// // 	}
// // 	if (map->player != 1)
// // 		return (0);
// // 	if (map->collectible < 1)
// // 		return (0);
// // 	if (map->exit < 1)
// // 		return (0);
// // 	return (1);
// // }	

// // if (flood_fill(map, map->player->y, map->player->x, '0', 'X', &map->count, map->visited))
// //             printf("True: P can reach E and collect all C\n");
// //         else
// //             printf("False: P can't reach E or didn't collect all C\n");