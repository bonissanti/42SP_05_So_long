#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

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
        exit(1);
    }
}

void load_sprites(t_game *game, t_map *map)
{
    int width;
    int height;
    
    map->moves = 0;
    game->player.sprites.background = mlx_xpm_file_to_image(game->mlx, BACKGROUND, &width, &height);
    // game->player.sprites.mario_r = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_r.xpm", &width, &height);
    game->player.sprites.mario_l = mlx_xpm_file_to_image(game->mlx, IDLE_L, &width, &height);
    // game->player.sprites.mario_u = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_u.xpm", &width, &height);
    // game->player.sprites.mario_d = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_d.xpm", &width, &height);
    game->player.sprites.wall = mlx_xpm_file_to_image(game->mlx, WALL, &width, &height);
    game->player.sprites.collectible = mlx_xpm_file_to_image(game->mlx, COINS, &width, &height);
    game->player.sprites.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &width, &height);
    // game->player.sprites.victory = mlx_xpm_file_to_image(game->mlx, "./sprites/victory.xpm", &width, &height);

    if (!game->player.sprites.background || !game->player.sprites.mario_l || !game->player.sprites.wall || !game->player.sprites.collectible || !game->player.sprites.exit)
    {
        printf("Error loading sprites\n");
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
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, game->player.x, game->player.y);
                else if (game->player.direction_y < 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, game->player.x, game->player.y);
                else if (game->player.direction_y > 0)
                    mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, game->player.x, game->player.y);
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
    printf("Drawing Mario at x: %d, y: %d\n", game->player.x / 46, game->player.y / 46);
}


int no_event(t_game *game)
{
    (void)game;
    return (0);
}

void mlx_hooks(t_game *game)
{
    // mlx_key_hook(game->window, &key_press, game);
    mlx_loop_hook(game->mlx, &no_event, game);
    mlx_hook(game->window, 2, 1L << 0, &key_press, game);
    mlx_hook(game->window, 17, 1L << 17, &close_window, game);
    mlx_loop(game->mlx);
}



// int game_loop(t_game *game)
// {
//     mlx_clear_window(game->mlx, game->window);
//     draw_game(game, game->map);
//     return (0);
// }






// if (map->moves == 0)
    //     mlx_string_put(game->mlx, game->window, 10, 10, 0x00FFFFFF, "Moves: 0");
    // else
    //     mlx_string_put(game->mlx, game->window, 10, 10, 0x00FFFFFF, ft_itoa(map->moves));

// void draw_game(t_game *game, t_map *map)
// {
//     int row;
//     int col;

//     row = 0;
//     mlx_clear_window(game->mlx, game->window);
//     while (row <= map->rows)
//     {
//         col = 0;
//         while (col <= map->columns)
//         {
//             mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.background, col * BG_SIZE, row * BG_SIZE);
//             col++;
//         }
//         row++;
//     }

//     row = 0;
//     while (row < map->rows)
//     {
//         col = 0;
//         while (col < map->columns)
//         {
//             if (map->matriz[row][col] == '1')
//                 mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.wall, col * SPRITE_SIZE, row * SPRITE_SIZE);
//             else if (map->matriz[row][col] == 'C')
//                 mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.collectible, col * SPRITE_SIZE, row * SPRITE_SIZE);
//             else if (map->matriz[row][col] == 'E')
//                 mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.exit, col * SPRITE_SIZE, row * SPRITE_SIZE);
//             else if (map->matriz[row][col] == 'P')
//             {
//                 game->player.x = col * MARIO_SIZE;
//                 game->player.y = row * MARIO_SIZE;
//                 mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_l, col * SPRITE_SIZE, row * SPRITE_SIZE);
//             }
//             col++;
//         }
//         row++;
//     }
// }