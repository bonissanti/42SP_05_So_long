/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:13:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:05:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map(t_map *map);
int		read_lines(t_map *map);
void	get_map(t_map *map);
void	allocate_map(t_map *map);
void	read_map(t_map *map, int fd);
int		check_file(char *file);

void	init_map(t_map *map)
{
	get_map(map);
	if (!check_wall(map))
	{
		ft_printf("Error\nMap must be surrounded by walls\n");
		free_map(map);
		exit(1);
	}
	check_size(map);
	valid_char(map);
	check_players(map);
	check_exit(map);
	count_coins(map);
	if (map->coins == 0)
	{
		ft_printf("Error\nMap must have at least one coins\n");
		free_map(map);
		exit(1);
	}
}

void	allocate_map(t_map *map)
{
	check_file(map->file);
	map->rows = get_lines(map);
	if (map->rows <= 0)
	{
		ft_printf("Error\nMap cannot be empty\n");
		exit(1);
	}
<<<<<<<< HEAD:src/1.init/get_map.c
========
	line_count = 0;
	while ((bytes_read = read(fd, buffer, 4096)))
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n' || buffer[i] == '\0')
				line_count++;
			i++;
		}
	}
	close(fd);
	return (line_count);
}

void	get_map(t_map *map)
{
	int		fd;
	int		i;

	check_file(map->file);
	map->rows = count_lines(map);
>>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4:src/1.init/init_map.c
	map->matriz = malloc(sizeof(char *) * (map->rows));
	if (!map->matriz)
	{
		ft_printf("Error allocating memory\n");
		exit(1);
	}
}

void	read_map(t_map *map, int fd)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		map->matriz[i] = get_next_line(fd);
		if (map->matriz[i] == NULL)
		{
			ft_printf("Error\nMap cannot be empty\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
	if (map->matriz[0] == NULL)
	{
		ft_printf("Error\nMap cannot be empty\n");
		free_map(map);
		exit(1);
	}
	map->columns = ft_strlen(map->matriz[0]);
}

void	get_map(t_map *map)
{
	int	fd;

	allocate_map(map);
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		exit(1);
	}
	read_map(map, fd);
	close(fd);
}

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == NULL)
	{
		ft_printf("Error\nNo file\n");
		exit(1);
	}
	if (len < 4)
		return (0);
	else if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nFile must be .ber\n");
		exit(1);
	}
	return (1);
}
