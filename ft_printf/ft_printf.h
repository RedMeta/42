/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:42:30 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 13:42:32 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONV_TYPES "%cspdiuxX"
# define CONV_FLAGS "-0.*"
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

struct s_flags
{
	char	conv;
	bool	flags[2];
	int		prec;
	int		s_width;
	int		m_width;

};

typedef	struct s_flags t_flags;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(int n, char *base);
void	width_n_prec(const char *str, t_flags *flags, int max);
int		ft_check_flags(const char *str, va_list args, int *count);
int		flag_init(const char *str, t_flags* flags);
int		ft_atoi(const char *str);
int		ft_chrFnd(const char *str, char c);
int		ft_printf(const char *input, ...);

#endif
