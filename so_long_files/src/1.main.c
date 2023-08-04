/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/08/04 17:36:00 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"


int main(void)
{
    t_game      game;
    t_map       map;
    t_sprites   sprites;

    game.map = map;

    map.file = "../maps/map-test.ber";
    get_map(&map);
    call_checks(&map);
    check_path(&map);
    init_game(&game, &map);
    load_sprites(&game, &map);
    draw_game(&game, &map);
    update_player(&game.player, &map);
    mlx_hooks(&game);
}

    // draw_map(&game, &map);
    // mlx_put_image_to_window(game.mlx, game.window, game.player.sprites.wall, 0, 0);

    // mlx_put_image_to_window(game.mlx, game.window, game.player.sprites.background, 0, 0);
    // mlx_put_image_to_window(game.mlx, game.window, game.player.sprites.mario_l, 0, 0);
// int main(int argc, char *argv[])
// {
//     t_game      game;
//     t_map       map;
//     t_sprites   sprites;

//     if (argc != 2)
//     {
//         printf("Error\nWrong number of arguments\n");
//         exit(EXIT_FAILURE);
//     }
//     game.map = map;

//     map.file = argv[1];
//     // read_map(&map);
//     // is_valid_map(&map);
//     init_game(&game, &map);
//     load_sprites(&game, &map);
//     mlx_hooks(&game);
// }


// int	main(int argc, char *argv[])
// {
// 	t_game	game;
// 	t_map	map;
// 	t_sprites	sprites;

// 	if (argc != 2)
// 	{
// 		ft_printf("Error\nWrong number of arguments\n");
// 		exit(EXIT_FAILURE);
// 	}	
// 	map = read_map(argv[1]);
// }



// int	main(void)
// {
//     t_game data;

//     data.mlx_ptr = mlx_init();
//     if (data.mlx_ptr == NULL)
//         return (EXIT_FAILURE);

        
//     data.window_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
//     if (data.window_ptr == NULL)
//     {
//         mlx_destroy_display(data.mlx_ptr);
//         free(data.mlx_ptr);
//         return (EXIT_FAILURE);
//     }
    
//     data.sprites.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
//     if (data.sprites.img_ptr == NULL)
//     {
//         mlx_destroy_window(data.mlx_ptr, data.window_ptr);
//         mlx_destroy_display(data.mlx_ptr);
//         free(data.mlx_ptr);
//         return (EXIT_FAILURE);
//     }
    
//     data.sprites.addr = mlx_get_data_addr(data.sprites.img_ptr, &data.sprites.bits_per_pixel, &data.sprites.line_length, &data.sprites.endian);
//     if(data.sprites.addr == NULL)
//     {
//         mlx_destroy_image(data.mlx_ptr, data.sprites.img_ptr);
//         mlx_destroy_window(data.mlx_ptr, data.window_ptr);
//         mlx_destroy_display(data.mlx_ptr);
//         free(data.mlx_ptr);
//         return (EXIT_FAILURE);
//     }

//     mlx_hook(data.window_ptr, 2, 1L<<0, &key_press_esc, &data);
//     mlx_loop_hook(data.mlx_ptr, &render, &data);
//     mlx_loop(data.mlx_ptr);

//     mlx_destroy_image(data.mlx_ptr, data.sprites.img_ptr);
//     mlx_destroy_display(data.mlx_ptr);
//     free(data.mlx_ptr);
//     return (0);
// }