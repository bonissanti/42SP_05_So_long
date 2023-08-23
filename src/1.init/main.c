/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/22 13:27:22 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * Function: int main
 * -----------------
 * This is the main function of the program. My map, the argv[1], is passed
 * as an argument to the program. If the number of arguments is different
 * than 2, it will print an error message and exit the program. If the number
 * of arguments is correct, it will initialize the structs, the map, the game
 * and the sprites. Then it will load the sprites and call the mlx_hooks function
 *
 * @param: argc - The number of arguments passed to the program.
 * @param: argv - The arguments passed to the program.
 *
 * @return: Is an int function, it will return 1 if the number of arguments is
 * wrong, and 0 if the number of arguments is correct.
 *
 */

int	main(int argc, char *argv[])
{
	t_game	game;

	game.map.file = argv[1];
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (1);
	}
	init_structs(&game);
	init_map(&game.map);
	flood_fill(&game.map);
	init_game(&game);
	init_objects(&game, &game.objects, &game.num_obj, game.max_obj);
	load_sprites(&game, &game.map);
	mlx_hooks(&game);
}
