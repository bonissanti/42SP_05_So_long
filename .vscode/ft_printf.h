/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunrodr <brunrodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:25:42 by brunrodr          #+#    #+#             */
/*   Updated: 2023/06/20 15:22:21 by brunrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	unsigned int	hashtag;
	unsigned int	plus;
	unsigned int	space;
}					t_flags;

//####################### ft_printf ########################

int					ft_printf(const char *str, ...);

//####################### Specifiers #######################

int					print_base(int arg, int base);
int					print_char(int arg);
int					print_int(int arg, t_flags flags);
int					print_percent(void);
int					print_pointer(unsigned long int arg, int base);
int					print_string(char *arg);
int					print_unsign_int(unsigned int arg);
int					print_hex_d(unsigned int arg, int uppercase, t_flags flags);

//####################### Utils #######################

int					putnbr_ptr(unsigned long int value, int base);
int					putnbr_hex(unsigned int value, int base, int uppercase);
int					putnbr_int(int value, int base);
void				ft_putchar(char c);
int					get_specifier_length(const char *format);
int					check_uppercase(const char format);
void				active_flags(const char **format, t_flags *flags);

#endif