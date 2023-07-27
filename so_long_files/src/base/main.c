/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:00:47 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/27 10:49:31 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../../my_libft/include/libft.h"


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

int	main(void)
{
    t_game data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (EXIT_FAILURE);

        
    data.window_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "so_long");
    if (data.window_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (EXIT_FAILURE);
    }
    
    data.sprites.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (data.sprites.img_ptr == NULL)
    {
        mlx_destroy_window(data.mlx_ptr, data.window_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (EXIT_FAILURE);
    }
    
    data.sprites.addr = mlx_get_data_addr(data.sprites.img_ptr, &data.sprites.bits_per_pixel, &data.sprites.line_length, &data.sprites.endian);
    if(data.sprites.addr == NULL)
    {
        mlx_destroy_image(data.mlx_ptr, data.sprites.img_ptr);
        mlx_destroy_window(data.mlx_ptr, data.window_ptr);
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (EXIT_FAILURE);
    }

    mlx_hook(data.window_ptr, 2, 1L<<0, &key_press_esc, &data);
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_loop(data.mlx_ptr);

    mlx_destroy_image(data.mlx_ptr, data.sprites.img_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    return (0);
}