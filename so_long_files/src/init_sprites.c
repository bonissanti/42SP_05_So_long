#include "../../my_libft/include/libft.h"
#include "../include/so_long.h"

void	object_set(t_object *object, int x, int y, int width, int height)
{
	if (!object)
		return ;
	object->x = x;
	object->y = y;
	object->width = width;
	object->height = height;
}