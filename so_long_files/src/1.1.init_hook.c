#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void init_structs(t_game *game)
{
    game->map.rows = 0;
    game->map.columns = 0;
    game->map.matriz = NULL;
    game->map.position_x = 0;
    game->map.position_y = 0;
    game->map.moves = 0;
    game->current_coins = 0;
    game->current_bg = 0;
    game->frame_counter = 0;
    game->frame_bg = 0;
    game->current_mario_l = 0;
    game->frame_mario_l = 0;
    game->current_mario_r = 0;
    game->frame_mario_r = 0;
    game->current_mario_u = 0;
    game->frame_mario_u = 0;
    game->current_mario_d = 0;
    game->frame_mario_d = 0;
    game->player.x = 0;
    game->player.y = 0;
    game->player.direction_x = 0;
    game->player.direction_y = 0;
    game->player.sprites.background[0] = NULL;
    game->player.sprites.background[1] = NULL;
    game->player.sprites.background[2] = NULL;
    game->player.sprites.background[3] = NULL;

    game->player.sprites.mario_l[0] = NULL;
    game->player.sprites.mario_l[1] = NULL;
    game->player.sprites.mario_l[2] = NULL;

    game->player.sprites.mario_r[0] = NULL;
    // game->player.sprites.mario_r[1] = NULL;
    // game->player.sprites.mario_r[2] = NULL;

    game->player.sprites.mario_u[0] = NULL;
    game->player.sprites.mario_u[1] = NULL;
    game->player.sprites.mario_u[2] = NULL;

    game->player.sprites.mario_d[0] = NULL;
    game->player.sprites.mario_d[1] = NULL;
    game->player.sprites.mario_d[2] = NULL;

    game->player.sprites.wall = NULL;
    game->player.sprites.coins[0] = NULL;
    game->player.sprites.coins[1] = NULL;
    game->player.sprites.coins[2] = NULL;
    game->player.sprites.exit = NULL;
    game->player.sprites.victory = NULL;
}

void init_game(t_game *game, t_map *map)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error initializing mlx\n");
        exit(1);
    }
    
    game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    if (!game->window)
    {
        printf("Error creating window\n");
        free(game->mlx);
        exit(1);
    }
}

void load_sprites(t_game *game, t_map *map)
{
    int width;
    int height;
    
    map->moves = 0;
    game->player.sprites.background[0] = mlx_xpm_file_to_image(game->mlx, BACKGROUND, &width, &height);
    game->player.sprites.background[1] = mlx_xpm_file_to_image(game->mlx, BACKGROUND2, &width, &height);
    game->player.sprites.background[2] = mlx_xpm_file_to_image(game->mlx, BACKGROUND3, &width, &height);
    game->player.sprites.background[3] = mlx_xpm_file_to_image(game->mlx, BACKGROUND4, &width, &height);

    game->player.sprites.mario_r[0] = mlx_xpm_file_to_image(game->mlx, MARIO_R1, &width, &height);
    game->player.sprites.mario_r[1] = mlx_xpm_file_to_image(game->mlx, MARIO_R2, &width, &height);
    game->player.sprites.mario_r[2] = mlx_xpm_file_to_image(game->mlx, MARIO_R3, &width, &height);

    game->player.sprites.mario_l[0] = mlx_xpm_file_to_image(game->mlx, MARIO_L1, &width, &height);
    game->player.sprites.mario_l[1] = mlx_xpm_file_to_image(game->mlx, MARIO_L2, &width, &height);
    game->player.sprites.mario_l[2] = mlx_xpm_file_to_image(game->mlx, MARIO_L3, &width, &height);

    game->player.sprites.mario_u[0] = mlx_xpm_file_to_image(game->mlx, MARIO_U1, &width, &height);
    game->player.sprites.mario_u[1] = mlx_xpm_file_to_image(game->mlx, MARIO_U2, &width, &height);
    game->player.sprites.mario_u[2] = mlx_xpm_file_to_image(game->mlx, MARIO_U3, &width, &height);
    
    
    game->player.sprites.mario_d[0] = mlx_xpm_file_to_image(game->mlx, MARIO_D1, &width, &height);
    game->player.sprites.mario_d[1] = mlx_xpm_file_to_image(game->mlx, MARIO_D2, &width, &height);
    game->player.sprites.mario_d[2] = mlx_xpm_file_to_image(game->mlx, MARIO_D3, &width, &height);


    game->player.sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
    game->player.sprites.coins[0] = mlx_xpm_file_to_image(game->mlx, COINS, &width, &height);
    game->player.sprites.coins[1] = mlx_xpm_file_to_image(game->mlx, COINS2, &width, &height);
    game->player.sprites.coins[2] = mlx_xpm_file_to_image(game->mlx, COINS3, &width, &height);
    game->player.sprites.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
    if (!game->player.sprites.background[0] || !game->player.sprites.background[1] || !game->player.sprites.background[2] || !game->player.sprites.background[3] 
        || !game->player.sprites.mario_r[0] || !game->player.sprites.mario_r[1] || !game->player.sprites.mario_r[2] 
        || !game->player.sprites.mario_d[0] || !game->player.sprites.mario_d[1] || !game->player.sprites.mario_d[2]
        
        || !game->player.sprites.mario_l[0] || !game->player.sprites.mario_l[1] || !game->player.sprites.mario_l[2] || !game->player.sprites.mario_u[0] 
        || !game->player.sprites.mario_u[1] || !game->player.sprites.mario_u[2] || !game->player.sprites.wall 
        || !game->player.sprites.coins[0] || !game->player.sprites.coins[1] || !game->player.sprites.coins[2] || !game->player.sprites.exit)
    {
        printf("Error loading sprites\n");
        free_game(game);
        exit(1);
    }
    find_start_position(&game->map, &game->map.position_x, &game->map.position_y);
    game->player.x = game->map.position_x * SPRITE_SIZE;
    game->player.y = game->map.position_y * SPRITE_SIZE;
    draw_game(game, map);
}


void draw_mario(t_game *game, t_map *map)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->columns)
        {
            if (map->matriz[row][col] == 'P')
            {
                if (game->player.direction_x < 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l[game->current_mario_l], game->player.x, game->player.y);
                else if (game->player.direction_x > 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_r[game->current_mario_r], game->player.x, game->player.y);
                else if (game->player.direction_y < 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_u[game->current_mario_u], game->player.x, game->player.y);
                else if (game->player.direction_y > 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_d[game->current_mario_d], game->player.x, game->player.y);
                else
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_r[game->current_mario_r], game->player.x, game->player.y);
            }
            col++;
        }
        row++;
    }
}

void draw_background(t_game *game, t_map *map)
{
    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.background[game->current_bg], 0, 0);
}

void draw_wall(t_game *game, t_map *map)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->columns)
        {
            if (map->matriz[row][col] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.wall, col * SPRITE_SIZE, row * SPRITE_SIZE);
            col++;
        }
        row++;
    }
}

void draw_coins(t_game *game, t_map *map)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->columns)
        {
            if (map->matriz[row][col] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.coins[game->current_coins], col * SPRITE_SIZE, row * SPRITE_SIZE);
            col++;
        }
        row++;
    }
    
}

void draw_exit(t_game *game, t_map *map)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->columns)
        {
            if (map->matriz[row][col] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.exit, col * SPRITE_SIZE, row * SPRITE_SIZE);
            col++;
        }
        row++;
    }
}

void draw_game(t_game *game, t_map *map)
{
    mlx_clear_window(game->mlx, game->window);

    draw_background(game, map);
    draw_exit(game, map);
    draw_wall(game, map);
    draw_coins(game, map);
    draw_mario(game, map);
}


int no_event(t_game *game)
{
    (void)game;
    return (0);
}

int animation_loop(t_game *game)
{
    // game->buffer = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (game->frame_counter % 200 == 0)
        game->current_coins = (game->current_coins + 1) % 3;
    game->frame_counter++;

    if (game->frame_bg % 150 == 0)
        game->current_bg = (game->current_bg + 1) % 4;
    game->frame_bg++;

    if (game->frame_mario_l % 200 == 0)
        game->current_mario_l = (game->current_mario_l + 1) % 3;
    game->frame_mario_l++;

    if (game->frame_mario_r % 200 == 0)
        game->current_mario_r = (game->current_mario_r + 1) % 3;
    game->frame_mario_r++;

    if (game->frame_mario_u % 200 == 0)
        game->current_mario_u = (game->current_mario_u + 1) % 3;
    game->frame_mario_u++;

    if (game->frame_mario_d % 200 == 0)
        game->current_mario_d = (game->current_mario_d + 1) % 3;
    game->frame_mario_d++;

    draw_game(game, &game->map);

    return (0);
}

void mlx_hooks(t_game *game)
{
    mlx_loop_hook(game->mlx, &animation_loop, game);
    mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 17, 1L << 17, &close_window, game);
    mlx_loop(game->mlx);
}
