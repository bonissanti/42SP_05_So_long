#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"

int check_bg_color(t_color *color)
{
    if (color->r == 0 && color->g == 168 && color->b == 7)
        return (1);
    return (0);
}

void change_bg_color(t_game *game, void *sprites, int width, int height)
{
    int bpp;
    int size_line;
    int endian;
    char *mlx_addr;

    int y = 0;
    t_color *color_ptr;
    mlx_addr = mlx_get_data_addr(sprites, &bpp, &size_line, &endian);

    while (y < height)
    {
        int x = 0;
        while (x < width)
        {
            int pixel_pos = (y * size_line) + (x * (bpp / 8));
            color_ptr = (t_color *)(mlx_addr + pixel_pos);

            if (check_bg_color(color_ptr))
            {
                color_ptr->r = 0;
                color_ptr->g = 0;
                color_ptr->b = 0;
                color_ptr->a = 0;
            }
            x++;
        }
        y++;
    }
}