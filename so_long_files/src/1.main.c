/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/04 18:39:53 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"


int main(void)
{
    t_game      game;
    t_map       map;
    t_sprites   sprites;

    game.map = map;

    map.file = "../maps/map-test.ber";
    get_map(&map);
    call_checks(&map);
    check_path(&map);
    init_game(&game, &map);
    load_sprites(&game, &map);
    mlx_hooks(&game);
}
