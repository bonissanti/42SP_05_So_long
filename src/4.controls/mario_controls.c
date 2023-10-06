/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mario_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:49:21 by brunrodr          #+#    #+#             */
/*   Updated: 2023/10/06 18:38:25 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	r_key(int *next_x, int *direction_x, int *direction_y);
void	u_key(int *next_y, int *direction_x, int *direction_y);
void	d_key(int *next_y, int *direction_x, int *direction_y);
void	l_key(int *next_x, int *direction_x, int *direction_y);
int		close_window(t_game *game);

/**
 * Function: r_key, u_key, d_key, l_key
 * -----------------
 * This functions controls the player movement to the right, up, down and left.
 * This function is called by the key_press function. It will increment the
 * next_x variable by 46, which is the size of the tiles (or speed), and will set the
 * direction_x variable to 1 and the direction_y variable to 0, when the right
 * key is pressed. The same happens with the other functions, but with different
 * variables. Direction_x and direction_y are used to animate the sprites.
 * 
 * @param: *next_x - Pointer to the next_x variable.
 * @param: *direction_x - Pointer to the direction_x variable.
 * @param: *direction_y - Pointer to the direction_y variable.
 *
 * @return: Is a void function.
 *
 */

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

/**
 * Function: Close window
 * -----------------
 * This functions closes the window and frees the memory allocated for the game
 * struct.
 * 
 * @param: *game - Pointer to the game struct.
 *
 * @return: Is a void function.
 *
 */

int	close_window(t_game *game)
{
	ft_printf("You closed the window!\n");
	free_game(game);
	return (1);
}
