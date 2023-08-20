/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:15:58 by brunrodr          #+#    #+#             */
/*   Updated: 2023/06/07 11:12:46 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the header file for the get_next_line function.
** It contains the prototypes of the functions used in the get_next_line function.
** It also contains the BUFFER_SIZE. The BUFFER_SIZE is the size of the buffer
** that will be read. The BUFFER_SIZE can be changed during the compilation.
** If the BUFFER_SIZE is not defined, it will be defined as 50.
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

//####################  GNL ###################

char	*get_next_line(int fd);

//##################  UTILS  ##################

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(char *s);

#endif