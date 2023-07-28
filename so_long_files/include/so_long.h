/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:04:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/28 16:11:19 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdint.h>



// #include "libft.h"


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
# define ERR_MAP_OPEN "Error\nCould not open map\n"
# define ERR_MAP_READ "Error\nCould not read map\n"
# define ERR_MAP_CLOSE "Error\nCould not close map\n"
# define ERR_MAP_EMPTY "Error\nMap is empty\n"
# define ERR_MAP_LINE "Error\nMap lines must be of equal length\n"
# define ERR_MAP_CHAR "Error\nMap contains invalid characters\n"
# define ERR_MAP_RECT "Error\nMap is not rectangular\n"
# define ERR_MAP_PLAYER "Error\nMap must have one player\n"
# define ERR_MAP_COLLECT "Error\nMap must have at least one collectible\n"
# define ERR_MAP_EXIT "Error\nMap must have at least one exit\n"
# define ERR_MAP_WALL "Error\nMap must be surrounded by walls\n"
# define ERR_MAP_WALL_IN "Error\nMap must have walls inside\n"
# define ERR_MAP_WALL_OUT "Error\nMap must have walls outside\n"

//########################## STRUCTS ##########################################

typedef struct s_sprites
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_sprites;

typedef struct s_map
{
	unsigned int	moves;
	char			**map_matriz;
	char			*file;
	int				rows;
	int				columns;
	int				player_x;
	int				player_y;
	int				player;
	int				collectible;
	int				c_count;
	int				exit;
	int				empty;
	int				wall;
}					t_map;


typedef struct s_game
{
	void		*mlx_ptr;
	void		*window_ptr;
	int			steps;
	t_sprites	sprites;
	t_map		map;
}			t_game;


//########################## FUNCTIONS ########################################
//########################## BASE #############################################

int		color_rgb(int r, int g, int b, int a);
int		key_press_esc(int keycode, t_game *data);
void	img_pixel_put(t_sprites *sprites, int x, int y, int color);
int		render(t_game *game);

//########################## DRAW #############################################

int	draw_background(t_game *game, int color);


#endif