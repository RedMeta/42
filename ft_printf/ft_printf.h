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

struct t_flags
{
	char	conv;
	char	fill;
	int		side;
	int		s_width;
	int		m_width;

} flags;

typedef	struct t_flags s_flags;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(int n, char *base);
void	ft_check_flags(const char *str, va_list args, int count);
void	flag_init(const char *str, s_flags* flags);
int		ft_atoi(const char *str);
int		ft_chrFnd(const char *str, char c);
int		ft_printf(const char *input, ...);

#endif
