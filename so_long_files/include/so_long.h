/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:04:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/09 18:20:03 by brunrodr         ###   ########.fr       */
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
# define WIN_WIDTH 920
# define WIN_HEIGHT 780

//########################### GAME CONFIG #####################################

# define SPRITE_SIZE 46
# define GRAVITY 1
# define GROUND_HEIGHT 9

//########################### SPRITES #########################################

# define MARIO_R1 "../sprites/mario_r1.xpm"
# define MARIO_U1 "../sprites/mario_u1.xpm"
# define MARIO_D1 "../sprites/mario_d1.xpm"
# define MARIO_L1 "../sprites/mario_l1.xpm"
# define WALL "../sprites/wall.xpm"
# define COINS "../sprites/coins_1.xpm"
# define EXIT "../sprites/exit.xpm"
// # define VICTORY "./sprites/victory.xpm"
# define BACKGROUND "../sprites/background-u.xpm"

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
	void	*mario_l;
	void	*mario_r;
	void	*mario_u;
	void	*mario_d;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*victory;
	void	*background;
}			t_sprites;

typedef struct s_player
{
	int x;
	int y;
	int direction_x;
	int direction_y;
	int player_idle;
	t_sprites sprites;

}		t_player;

typedef enum e_state
{
	PLAYING,
	VICTORY,
	DEFEAT
}			t_state;


typedef struct s_map
{
	unsigned int	moves;
	char			**matriz;
    char			*file;
	int				rows;
	int				columns;
	int				player;
	int				collectible;
	int				c_count;
	int				exit;
	int				empty;
	int				wall;
	int				position_x;
	int 			position_y;
	int				target;
	int				replacement;
	int				count;
	int				**visited;
}					t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			moves;
	t_map		map;
	t_player	player;
	t_state		state;
	t_sprites	sprites;
}				t_game;

typedef struct s_color
{
	int r;
	int g;
	int b;
	int a;
}               t_color;




//########################## FUNCTIONS ########################################
//########################## INIT GAME ########################################

void 	init_structs(t_game *game);
void	init_game(t_game *game, t_map *map);
void	load_sprites(t_game *game, t_map *map);
void 	draw_game(t_game *game, t_map *map);
void 	mlx_hooks(t_game *game);


//########################## CONTROLS #########################################

int		key_press(int keycode, t_game *game);
int 	close_window(t_game *game);
void	exit_game(t_game *game);


//########################## MAP ##############################################

int		count_lines(t_map *map);
void 	get_map(t_map *map);
void 	call_checks(t_map *map);
int 	check_size(t_map *map);
int 	check_wall(t_map *map);
void	count_collectibles(t_map *map);
int		valid_char(t_map *map);

//########################## ALGORITHM ########################################

void 	check_path(t_map *map);
int		flood_fill(t_map *map, int x, int y);
void	find_start_position(t_map *map, int *position_x, int *position_y);
char	**copy_matriz(char **original, int rows, int columns);
int		**visited_matriz(int rows, int columns);


//########################## MEMORY ###########################################

void	free_map(t_map *map);
void 	free_matriz(int **visited, int rows);
void	free_sprites(t_game *game);
void 	free_game(t_game *game);


//########################## UTILS ############################################

int 	check_bg_color(t_color *color);
void 	change_bg_color(t_game *game, void *sprites, int width, int height);
// void 	update_game(t_game *game);
int 	game_loop(t_game *game);

void draw_exit(t_game *game, t_map *map);
void draw_background(t_game *game, t_map *map);
void draw_wall(t_game *game, t_map *map);
void draw_collectible(t_game *game, t_map *map);
void draw_exit(t_game *game, t_map *map);
void draw_mario(t_game *game, t_map *map);
int 	check_next_position(int next_x, int next_y, t_game *game);




#endif