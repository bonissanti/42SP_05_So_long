#include "../include/so_long.h"
#include "../../my_libft/include/libft.h"

t_map *get_map(char *filename)
{
    int fd;
    char *line;
    t_map *map;
    int i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }

    map = malloc(sizeof(t_map));
    if (!map)
    {
        printf("Error allocating memory\n");
        exit(1);
    }

    i = 0;
    while ((line = get_next_line(fd)))
    {
        map->map[i] = line;
        i++;
        line = get_next_line(fd);
    }
    map->rows = i;
    map->columns = ft_strlen(map->map[0]);

    close(fd);
    return (map);

}

int main(void)
{
    t_map *map;
    int i;

    map = get_map("../maps/map.ber");
    i = 0;
    while (i < map->rows)
    {
        printf("%s\n", map->
        i++;
    }
    printf("rows: %d\n", map->rows);
    printf("columns: %d\n", map->columns);
    return (0);
}