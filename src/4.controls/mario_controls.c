/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:21 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/21 10:49:23 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	r_key(int *next_x, int *direction_x, int *direction_y);
void	u_key(int *next_y, int *direction_x, int *direction_y);
void	d_key(int *next_y, int *direction_x, int *direction_y);
void	l_key(int *next_x, int *direction_x, int *direction_y);
int		close_window(t_game *game);

void	r_key(int *next_x, int *direction_x, int *direction_y)
{
	*next_x += 46;
	*direction_x = 1;
	*direction_y = 0;
}

void	u_key(int *next_y, int *direction_x, int *direction_y)
{
	*next_y -= 46;
	*direction_x = 0;
	*direction_y = -1;
}

void	d_key(int *next_y, int *direction_x, int *direction_y)
{
	*next_y += 46;
	*direction_x = 0;
	*direction_y = 1;
}

void	l_key(int *next_x, int *direction_x, int *direction_y)
{
	*next_x -= 46;
	*direction_x = -1;
	*direction_y = 0;
}

int	close_window(t_game *game)
{
	ft_printf("You closed the window!\n");
	free_game(game);
	return (1);
}
