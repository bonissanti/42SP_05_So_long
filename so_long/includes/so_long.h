/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:04:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/21 18:00:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

//########################### WINDOW CONFIG ###################################

# define WIN_TITLE "Super Mario World - 42 edition"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

//########################## KEY CONFIG #######################################

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

//########################## ERROR MESSAGES ###################################

# define ERR_NO_MAP "Error\nNo map provided\n"
# define ERR_MAP_EXT "Error\nMap must have .ber extension\n"

//########################## STRUCTS ##########################################

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;


#endif