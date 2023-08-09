/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/09 13:00:19 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"


int main(void)
{
    t_game      game;
    //t_map       map;

    //game.map = map;

    game.map.file = "../maps/map-test.ber";
    get_map(&game.map);
    call_checks(&game.map);
    check_path(&game);
    init_game(&game, &game.map);
    load_sprites(&game, &game.map);
    mlx_hooks(&game);
}
