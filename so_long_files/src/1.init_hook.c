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
    game->player.x = 0;
    game->player.y = 0;
    game->player.direction_x = 0;
    game->player.direction_y = 0;
    game->player.sprites.background = NULL;
    game->player.sprites.mario_l = NULL;
    game->player.sprites.mario_r = NULL;
    game->player.sprites.mario_u = NULL;
    game->player.sprites.mario_d = NULL;
    game->player.sprites.wall = NULL;
    game->player.sprites.collectible = NULL;
    game->player.sprites.exit = NULL;
    game->player.sprites.victory = NULL;
}

void init_game(t_game *game, t_map *map)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error creating mlx\n");
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
    game->player.sprites.background = mlx_xpm_file_to_image(game->mlx, BACKGROUND, &width, &height);
    game->player.sprites.mario_r = mlx_xpm_file_to_image(game->mlx, MARIO_R1, &width, &height);
    game->player.sprites.mario_l = mlx_xpm_file_to_image(game->mlx, MARIO_L1, &width, &height);
    game->player.sprites.mario_u = mlx_xpm_file_to_image(game->mlx, MARIO_U1, &width, &height);
    game->player.sprites.mario_d = mlx_xpm_file_to_image(game->mlx, MARIO_D1, &width, &height);
    game->player.sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
    game->player.sprites.collectible = mlx_xpm_file_to_image(game->mlx, COINS, &width, &height);
    game->player.sprites.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
    // game->player.sprites.victory = mlx_xpm_file_to_image(game->mlx, "./sprites/victory.xpm", &width, &height);
    if (!game->player.sprites.background || !game->player.sprites.mario_r  || !game->player.sprites.mario_l || !game->player.sprites.mario_u || !game->player.sprites.mario_d || !game->player.sprites.wall || !game->player.sprites.collectible || !game->player.sprites.exit)
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
    // printf("%i %i\n", map->rows, map->columns);
    while (row < map->rows)
    {
        col = 0;
        while (col < map->columns)
        {
            if (map->matriz[row][col] == 'P')
            {
                // printf("1. Drawing Mario at x: %d, y: %d\n", game->player.x, game->player.y);


                if (game->player.direction_x < 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, game->player.x, game->player.y);
                else if (game->player.direction_x > 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_r, game->player.x, game->player.y);
                else if (game->player.direction_y < 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_u, game->player.x, game->player.y);
                else if (game->player.direction_y > 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_d, game->player.x, game->player.y);
                else
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, game->player.x, game->player.y);
                // printf("2. Drawing Mario at x: %d, y: %d\n", game->player.x, game->player.y);
            }
            col++;
        }
        row++;
    }
}

void draw_background(t_game *game, t_map *map)
{
    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.background, 0, 0);
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

void draw_collectible(t_game *game, t_map *map)
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
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.collectible, col * SPRITE_SIZE, row * SPRITE_SIZE);
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
    draw_collectible(game, map);
    draw_mario(game, map);
}


int no_event(t_game *game)
{
    (void)game;
    return (0);
}

void mlx_hooks(t_game *game)
{
    mlx_loop_hook(game->mlx, &no_event, game);
    mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 17, 1L << 17, &close_window, game);
    mlx_loop(game->mlx);
}
