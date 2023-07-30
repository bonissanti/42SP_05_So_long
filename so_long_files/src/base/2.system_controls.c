/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:40:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/25 18:50:58 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        exit_game(game);
    // else if (keycode == KEY_UP)
    //     mario_move_up(&game->player);
    else if (keycode == KEY_RIGHT)
        mario_move_right(&game->player);
    else if (keycode == KEY_LEFT)
        mario_move_left(&game->player);
    else if (keycode == KEY_DOWN)
        mario_move_down(&game->player);
    else if (keycode == KEY_SPACE)
        jump(&game->player, &game->map);
    return (0);
}

// function to close the game through X button

void close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    exit(0);
}

