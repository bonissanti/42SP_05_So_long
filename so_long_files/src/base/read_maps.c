/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:26:08 by brunrodr          #+#    #+#             */
/*   Updated: 2023/07/26 13:07:45 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../../../my_libft/include/libft.h"

static int	check_map_line(char *line, int *player, int *collect, int *exit)
{
	char	*ptr;
	int		*cols;

	ptr = line;
	cols = 0;
	while (*ptr)
	{
		if (*ptr == 'P')
			*player += 1;
		else if (*ptr == 'C')
			*collect += 1;
		else if (*ptr == 'E')
			*exit += 1;
		else if (*ptr != '1' && *ptr != '0')
			return (0);
		ptr++;
		(*cols)++;
	}
	return (1);
}



