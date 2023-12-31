/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:13:57 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 13:13:44 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	allocate_map(t_map *map)
{
	check_file(map->file);
	map->rows = get_lines(map);
	if (map->rows <= 0)
	{
		ft_printf("Error\nMap cannot be empty\n");
		exit(1);
	}
	map->matriz = malloc(sizeof(char *) * (map->rows));
	if (!map->matriz)
	{
		ft_printf("Error allocating memory\n");
		exit(1);
	}
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
	{
		ft_printf("Error\nFile must be .ber\n");
		exit(1);
	}
	else if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nFile must be .ber\n");
		exit(1);
	}
	return (1);
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
