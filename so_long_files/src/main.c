/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/16 12:21:59 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"


int main(void)
{
    t_game      game;

    game.map.file = "../maps/ultimate.ber";
    init_structs(&game);
    init_map(&game.map);
    flood_fill(&game.map);
    init_game(&game, &game.map);
    load_sprites(&game, &game.map);
    mlx_hooks(&game);
}

// int main(int argc, char *argv[])
// {
//     t_game      game;

//     game.map.file = argv[1];
//     if (argc != 2)
//     {
//         printf("Error\nWrong number of arguments\n");
//         return (1);
//     }

//     init_structs(&game);
//     init_map(&game.map);
//     flood_fill(&game.map);
//     init_game(&game, &game.map);
//     load_sprites(&game, &game.map);
//     mlx_hooks(&game);
// }
