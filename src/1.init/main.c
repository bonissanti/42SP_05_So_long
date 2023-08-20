/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:05 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
<<<<<<< HEAD
=======

// int main(void)
// {
//     t_game      game;

//     game.map.file = "../maps/ultimate.ber";
//     init_structs(&game);
//     init_map(&game.map);
//     flood_fill(&game.map);
//     init_game(&game, &game.map);
//     load_sprites(&game, &game.map);
//     mlx_hooks(&game);
// }
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4

int	main(int argc, char *argv[])
{
	t_game	game;

<<<<<<< HEAD
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
=======
    game.map.file = argv[1];
    if (argc != 2)
    {
        printf("Error\nWrong number of arguments\n");
        return (1);
    }

    init_structs(&game);
    init_map(&game.map);
    flood_fill(&game.map);
    init_game(&game);
    load_sprites(&game, &game.map);
    mlx_hooks(&game);
>>>>>>> 1c6e2679b2a3b698d740db3ddc3eecf76b3250a4
}
