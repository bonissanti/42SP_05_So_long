/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3..system_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:40:18 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/04 17:39:52 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == KEY_UP)
    {
        printf("up\n");
        mario_move_up(game);
    }
    else if (keycode == KEY_RIGHT)
        mario_move_right(game);
    else if (keycode == KEY_LEFT)
        mario_move_left(game);
    else if (keycode == KEY_DOWN)
        mario_move_down(game);
    return (0);
}



int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->window);
    exit(EXIT_SUCCESS);
    return (0);
}

    // mlx_destroy_display(game->mlx);
    // free(game->mlx);

