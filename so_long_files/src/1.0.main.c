/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/10 18:21:56 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"


int main(void)
{
    t_game      game;
    //t_map       map;

    //game.map = map;

    game.map.file = "../maps/mandatory_basic.ber";
    init_structs(&game);
    // get_map(&game.map);
    init_map(&game.map);
    flood_fill(&game.map);
    init_game(&game, &game.map);
    load_sprites(&game, &game.map);
    mlx_hooks(&game);
}
