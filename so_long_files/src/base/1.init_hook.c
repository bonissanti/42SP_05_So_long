#include "../../../my_libft/include/libft.h"
#include "../../include/so_long.h"

void init_game(t_game *game, t_map *map)
{
    game->mlx = mlx_init();
    {
        ft_printf("Error initializing mlx\n");
        exit(1);
    }
    game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
    {
        ft_printf("Error creating window\n");
        exit(1);
    }
}

void load_sprites(t_game *game, t_map *map)
{
    
    map->moves = 0;
    game->player.sprites.background = mlx_xpm_file_to_image(game->mlx, "./sprites/background.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.mario_l = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_l.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.mario_r = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_r.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.mario_u = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_u.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.mario_d = mlx_xpm_file_to_image(game->mlx, "./sprites/mario_d.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.wall = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.collectible = mlx_xpm_file_to_image(game->mlx, "./sprites/collectible.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.exit = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm", &game->player.sprites.width, &game->player.sprites.height);
    game->player.sprites.victory = mlx_xpm_file_to_image(game->mlx, "./sprites/victory.xpm", &game->player.sprites.width, &game->player.sprites.height);

    if (!game->player.sprites.background || !game->player.sprites.mario_l || !game->player.sprites.mario_r || !game->player.sprites.mario_u || !game->player.sprites.mario_d || !game->player.sprites.wall || !game->player.sprites.collectible || !game->player.sprites.exit || !game->player.sprites.victory)
    {
        ft_printf("Error loading sprites\n");
        exit_game(game);
        exit(1);
    }

}

void draw_map(t_game *game, t_map *map)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (column < map->columns)
        {
            if (map->matriz[row][col] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.wall, col * SPRITE_SIZE, row * SPRITE_SIZE);
            else if (map->matriz[row][col] == 'C')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.collectible, col * SPRITE_SIZE, row * SPRITE_SIZE);
            else if (map->matriz[row][col] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.exit, col * SPRITE_SIZE, row * SPRITE_SIZE);
            else if (map->matriz[row][col] == 'P')
            {
                game->player.x = col * SPRITE_SIZE;
                game->player.y = row * SPRITE_SIZE;
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.mario_r, col * SPRITE_SIZE, row * SPRITE_SIZE);
            }
            else if (map->matriz[row][col] == '0')
                mlx_put_image_to_window(game->mlx, game->window, game->player.sprites.background, col * SPRITE_SIZE, row * SPRITE_SIZE);
            col++;
        }
        row++;
    }
}

void mlx_hooks(t_game *game)
{
    mlx_loop_hook(game->mlx, draw_map, game);
    mlx_hook(game->window, 2, 1L << 0, key_press, game);
    mlx_hook(game->window, 17, 1L << 17, close_window, game);
    mlx_loop(game->mlx);
}