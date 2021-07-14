/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:00:55 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/25 18:07:08 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Includes
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

/*
** Enums
*/

typedef enum e_flags
{
	zero = 0,
	minus = 1
}				t_flags;

/*
** Structures
*/

typedef struct s_modifiers
{
	bool		flags[2];
	int			width;
	bool		width_state;
	int			precision;
	bool		upper_x;
}				t_modifiers;

/*
** Prototypes
*/

/*
** Main
*/

int				ft_printf(const char *format, ...);
void			ft_check_modifiers(va_list *args, const char *format, int *i,
					t_modifiers *modifiers);

/*
** Specs
*/

int				ft_spec_c(va_list *args, t_modifiers modifiers);
int				ft_spec_s(va_list *args, t_modifiers modifiers);
int				ft_spec_p(va_list *args, t_modifiers modifiers);
int				ft_spec_d(va_list *args, t_modifiers modifiers);
int				ft_spec_u(va_list *args, t_modifiers modifiers);
int				ft_spec_x(va_list *args, t_modifiers modifiers);
int				ft_spec_r(t_modifiers modifiers);

/*
** Utils
*/

int				ft_isdigit(int c);
int				ft_strlen(const char *s);
int				ft_numlen_base(int i, int base);
int				ft_unumlen_base(unsigned int i, int base);
int				ft_ulnumlen_base(unsigned long i, int base);
int				ft_special_atoi(const char *s, int *i);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstrlen_fd(char *s, int len, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_putunbr_fd(unsigned int n, int fd);
void			ft_putunbr_base_fd(unsigned long long nbr, char *base,
					int fd);

#endif
