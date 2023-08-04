/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:04:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/04 17:15:21 by brunrodr         ###   ########.fr       */
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

//########################### GAME CONFIG #####################################

# define SPRITE_SIZE 44
# define GRAVITY 1
# define GROUND_HEIGHT 9

//########################### SPRITES #########################################

// # define MARIO_L "./sprites/mario_l.xpm"
// # define MARIO_R "../sprites/mario_r.xpm"
// # define MARIO_U "./sprites/mario_u.xpm"
// # define MARIO_D "./sprites/mario_d.xpm"
# define IDLE_L "../sprites/mario_left_idle.xpm"
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
# define KEY_SPACE 32

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
	t_sprites sprites;
	int jumping;
	int on_ground;

}		t_player;

typedef enum e_game_state
{
	PLAYING,
	VICTORY,
	DEFEAT
}			t_game_state;


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
	int				player_x;
	int 			player_y;
	int				target;
	int				replacement;
	int				count;
	int				**visited;
}					t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	// int			moves;
	t_map		map;
	t_player	player;
	t_game_state state;
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

void	init_game(t_game *game, t_map *map);
void	load_sprites(t_game *game, t_map *map);
void 	draw_map(t_game *game, t_map *map);
void 	draw_background(t_game *game);			//TEMPORARIO
void 	draw_player(t_game *game); 				//TEMPORARIO
void 	draw_game(t_game *game);				//TEMPORARIO
void 	draw_wall(t_game *game, int x, int y);
void 	draw_collectible(t_game *game, int x, int y);
void 	draw_exit(t_game *game, int x, int y);
void 	mlx_hooks(t_game *game);
int 	game_loop(t_game *game);				//TEMPORARIO


//########################## CONTROLS #########################################

int		key_press(int keycode, t_game *game);
int 	close_window(t_game *game);
void	exit_game(t_game *game);
void 	jump(t_player *player, t_map *map);
void	mario_move_up(t_player *player);
void 	mario_move_down(t_map *map, t_player *player);
void 	mario_move_left(t_map *map, t_player *player);
void 	mario_move_right(t_map *map, t_player *player);
void 	update_player(t_player *player, t_map *map);

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
void	find_start_position(t_map *map, int *player_x, int *player_y);
char	**copy_matriz(char **original, int rows, int columns);
int		**visited_matriz(int rows, int columns);


//########################## MEMORY ###########################################

void	free_map(t_map *map);
void	free_sprites(t_game *game);
void	free_game(t_game *game, t_map *map);


//########################## UTILS ############################################

int 	check_bg_color(t_color *color);
void 	change_bg_color(t_game *game, void *sprites, int width, int height);



#endif