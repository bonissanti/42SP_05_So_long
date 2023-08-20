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

# include "../my_libft/include/libft.h"
# include <X11/X.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//########################### WINDOW CONFIG ###################################

# define WIN_TITLE "Super Mario World - 42 edition"
# define WIN_WIDTH 920
# define WIN_HEIGHT 780

//########################### GAME CONFIG #####################################

# define SPRITE_SIZE 46

//########################### SPRITES #########################################

# define MARIO_R1 "./textures/mario_r1.xpm"
# define MARIO_R2 "./textures/mario_r2.xpm"
# define MARIO_R3 "./textures/mario_r3.xpm"

# define MARIO_U1 "./textures/mario_u1.xpm"
# define MARIO_U2 "./textures/mario_u2.xpm"
# define MARIO_U3 "./textures/mario_u3.xpm"

# define MARIO_D1 "./textures/mario_d1.xpm"
# define MARIO_D2 "./textures/mario_d2.xpm"
# define MARIO_D3 "./textures/mario_d3.xpm"

# define MARIO_L1 "./textures/mario_l1.xpm"
# define MARIO_L2 "./textures/mario_l2.xpm"
# define MARIO_L3 "./textures/mario_l3.xpm"

# define WALL "./textures/wall.xpm"

# define COINS "./textures/coins_1.xpm"
# define COINS2 "./textures/coins_2.xpm"
# define COINS3 "./textures/coins_3.xpm"

# define EXIT "./textures/exit.xpm"
# define ENEMY "./textures/enemy.xpm"

# define BG "./textures/background_1.xpm"
# define BG2 "./textures/background_2.xpm"
# define BG3 "./textures/background_3.xpm"
# define BG4 "./textures/background_4.xpm"

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

//########################## STRUCTS ##########################################

typedef struct s_sprites
{
	void			*mario_l[3];
	void			*mario_r[3];
	void			*mario_u[3];
	void			*mario_d[3];
	void			*wall;
	void			*coins[3];
	void			*exit;
	void			*enemy;
	void			*bg[4];
	int				height;
	int				width;
}					t_sprites;

typedef struct s_player
{
	int				x;
	int				y;
	int				direction_x;
	int				direction_y;
	int				player_idle;

}					t_player;

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
	int				pos_y;
	int				target;
	int				replacement;
	int				count;
}					t_map;

typedef enum e_bool
{
	is_false,
	is_true
}					t_bool;

typedef struct s_object
{
	char			symbol;
	void			*sprite;
	int				x;
	int				y;
	t_bool			is_collected;
}					t_object;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				num_obj;
	int				max_obj;
	int				moves;
	int				coin_frame;
	int				coin_frame_counter;
	int				bg_frame;
	int				bg_frame_counter;
	int				mario_l_frame;
	int				mario_r_frame;
	int				mario_u_frame;
	int				mario_d_frame;
	int				last_anim_time;
	t_map			map;
	t_player		player;
	t_sprites		sprites;
	t_object		*objects;
}					t_game;

//########################## FUNCTIONS ########################################
//########################## INIT STRUCTS #####################################

void				init_structs(t_game *game);
void				init_map_defaults(t_game *game);
void				init_sprites_defaults(t_sprites *sprites);
void				init_player_defaults(t_player *player, t_sprites *sprites);

//########################## INIT GAME ########################################

void				init_game(t_game *game);
void				load_sprites(t_game *game, t_map *map);
void				load_bg_sprites(t_game *game);
void				load_mario_sprites(t_game *game);
void				load_others_sprites(t_game *game);
void				load_error(t_game *game);

//############################ DRAW ############################################

void				draw_background(t_game *game);
;
void				draw_exit_enemy(t_game *game, t_map *map);
void				draw_wall(t_game *game, t_map *map);
void				draw_coins(t_game *game, t_map *map);
void				draw_mario(t_game *game, t_map *map);
void				draw_sprite(t_game *game, void *sprite, int x, int y);
void				set_mario_sprite(t_game *game);

void				draw_game(t_game *game, t_map *map, t_object *object,
						int num_obj);
int					no_event(t_game *game);
void				animate_sprites(t_game *game);
void				mlx_hooks(t_game *game);

//########################## CONTROLS #########################################

int					key_press(int keycode, t_game *game);
void				l_key(int *next_x, int *direction_x, int *direction_y);
void				r_key(int *next_x, int *direction_x, int *direction_y);
void				u_key(int *next_y, int *direction_x, int *direction_y);
void				d_key(int *next_y, int *direction_x, int *direction_y);
int					close_window(t_game *game);

//########################## CONTROLS UTILS ###################################

int					check_next_position(int next_x, int next_y, t_game *game);
int					won_or_lost(t_game *game, char next_pos);
void				exit_game(t_game *game);

//########################## MAP ##############################################

void				init_map(t_map *map);
void				get_map(t_map *map);
void				allocate_map(t_map *map);
void				read_map(t_map *map, int fd);
int					get_lines(t_map *map);
int					count_lines(char *buffer, int bytes_read);

int					check_file(char *file);
void				check_players(t_map *map);
void				check_exit(t_map *map);
int					check_size(t_map *map);
int					check_wall(t_map *map);
void				count_coins(t_map *map);
int					valid_char(t_map *map);

//########################## ALGORITHM ########################################

void				flood_fill(t_map *map);
void				fill(t_map *map, int x, int y);
void				check_path(t_map *map);
void				find_start_position(t_map *map, int *pos_x, int *pos_y);
int					**visited_matriz(int rows, int columns);
int					cleanup_and_exit(t_map *map, int flag);

//########################## MEMORY ###########################################

void				free_map(t_map *map);
void				free_matriz(int **visited, int rows);
void				free_sprites(t_game *game);
void				free_player_sprites(t_game *game);
void				free_game(t_game *game);

//########################## OBJECTS ##########################################

void				init_objects(t_game *game, t_object **objects, int *num_obj,
						int max_obj);
void				allocate_objects(t_object **objects, int max_obj);
void				check_object(t_game *game, t_object **objects, int *num_obj,
						char symbol);
int					find_objects(t_game *game, t_object **objects, int *num_obj,
						char symbol);
void				draw_map_objects(t_game *game, t_object *objects,
						int num_obj);
void				cleanup_objects(t_object **objects);

#endif