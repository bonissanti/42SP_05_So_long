/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:04:34 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/10 17:29:52 by brunrodr         ###   ########.fr       */
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

# define MARIO_R1 "../textures/mario_r1.xpm"
# define MARIO_R2 "../textures/mario_r2.xpm"
# define MARIO_R3 "../textures/mario_r3.xpm"

# define MARIO_U1 "../textures/mario_u1.xpm"
# define MARIO_U2 "../textures/mario_u2.xpm"
# define MARIO_U3 "../textures/mario_u3.xpm"

# define MARIO_D1 "../textures/mario_d1.xpm"
# define MARIO_D2 "../textures/mario_d2.xpm"
# define MARIO_D3 "../textures/mario_d3.xpm"


# define MARIO_L1 "../textures/mario_l1.xpm"
# define MARIO_L2 "../textures/mario_l2.xpm"
# define MARIO_L3 "../textures/mario_l3.xpm"


# define WALL "../textures/wall.xpm"

# define COINS "../textures/coins_1.xpm"
# define COINS2 "../textures/coins_2.xpm"
# define COINS3 "../textures/coins_3.xpm"

# define EXIT "../textures/exit.xpm"
// # define VICTORY "./textures/victory.xpm"

# define BG "../textures/background_1.xpm"
# define BG2 "../textures/background_2.xpm"
# define BG3 "../textures/background_3.xpm"
# define BG4 "../textures/background_4.xpm"

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
# define ERR_MAP_COLLECT "Error\nMap must have at least one coins\n"
# define ERR_MAP_EXIT "Error\nMap must have at least one exit\n"
# define ERR_MAP_WALL "Error\nMap must be surrounded by walls\n"
# define ERR_MAP_WALL_IN "Error\nMap must have walls inside\n"
# define ERR_MAP_WALL_OUT "Error\nMap must have walls outside\n"

//########################## STRUCTS ##########################################

typedef struct s_sprites
{
	void	*mario_l[3];
	void	*mario_r[3];
	void	*mario_u[3];
	void	*mario_d[3];
	void	*wall;
	void	*coins[3];
	void	*exit;
	void	*victory;
	void	*bg[4];
	int		height;
	int		width;
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


typedef struct s_map
{
	unsigned int	moves;
	char			**matriz;
    char			*file;
	int				rows;
	int				columns;
	int				**visited;
	int				player;
	int				coins;
	int				c_count;
	int				exit;
	int				exit_count;
	int				empty;
	int				wall;
	int				pos_x;
	int 			pos_y;
	int				target;
	int				replacement;
	int				count;
}					t_map;

typedef struct s_animation
{
	void **sprites;
	int current_sprite;
	int frame_counter;
	int frame_rate;
} t_animation;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*buffer;
	char		*addr;
	int			moves;
	int			current_coins;
	int			frame_counter;
	int			current_bg;
	int			frame_bg;
	int			current_mario_l;
	int			frame_mario_l;
	int			current_mario_r;
	int			frame_mario_r;
	int			current_mario_u;
	int			frame_mario_u;
	int			current_mario_d;
	int			frame_mario_d;
	t_map		map;
	t_player	player;
	// t_state		state;
	t_sprites	sprites;
}				t_game;

// typedef struct s_color
// {
// 	int r;
// 	int g;
// 	int b;
// 	int a;
// }               t_color;




//########################## FUNCTIONS ########################################
//########################## INIT STRUCTS #####################################

void 	init_structs(t_game *game);
void 	init_map_defaults(t_game *game);
void 	init_player_defaults(t_player *player);
void 	init_sprites_defaults(t_sprites *sprites);

 //########################## INIT GAME ########################################

void	init_game(t_game *game, t_map *map);
void	load_sprites(t_game *game, t_map *map);
void	load_bg_sprites(t_game *game);
void	load_mario_sprites(t_game *game);
void	load_others_sprites(t_game *game);
void    load_error(t_game *game);

//############################ DRAW #############################################

void	draw_background(t_game *game, t_map *map);
void	draw_exit(t_game *game, t_map *map);
void	draw_wall(t_game *game, t_map *map);
void	draw_coins(t_game *game, t_map *map);
void	draw_mario(t_game *game, t_map *map);
void 	draw_sprite(t_game *game, void *sprite, int x, int y);
void 	set_mario_sprite(t_game *game, int direction_x, int direction_y);

void 	draw_game(t_game *game, t_map *map);
int 	animation_loop(t_game *game);
void 	mlx_hooks(t_game *game);


//########################## CONTROLS #########################################

int		key_press(int keycode, t_game *game);
void	l_key(int *next_x, int *direction_x, int *direction_y);
void	r_key(int *next_x, int *direction_x, int *direction_y);
void	u_key(int *next_y, int *direction_x, int *direction_y);
void	d_key(int *next_y, int *direction_x, int *direction_y);
int 	close_window(t_game *game);

//########################## CONTROLS UTILS ###################################

int		check_next_position(int next_x, int next_y, t_game *game);
int 	won_or_lost(t_game *game, char next_pos);
void	exit_game(t_game *game);

//########################## MAP ##############################################

void 	init_map(t_map *map);
void 	get_map(t_map *map);
int		count_lines(t_map *map);
int		check_file(char *file);
void 	check_players(t_map *map);
void 	check_exit(t_map *map);
int 	check_size(t_map *map);
int 	check_wall(t_map *map);
void	count_coins(t_map *map);
int		valid_char(t_map *map);

//########################## ALGORITHM ########################################

void	flood_fill(t_map *map);
void 	fill(t_map *map, int x, int y);
int check_path(t_map *map);
void	find_start_position(t_map *map, int *pos_x, int *pos_y);
char	**copy_matriz(char **original, int rows, int columns);
int		**visited_matriz(int rows, int columns);



//########################## MEMORY ###########################################

void	free_map(t_map *map);
void 	free_matriz(int **visited, int rows);
void	free_sprites(t_game *game);
void 	free_game(t_game *game);


//########################## UTILS ############################################



void *double_buffering(t_game *game);
int is_valid_char(char c);
void print_map(t_map map);




#endif