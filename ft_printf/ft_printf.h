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
# define CONV_TYPES "%csidupxX"
# define CONV_FLAGS "-0.*"
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

struct s_flags
{
	bool	flags[2];
	int		conv;
	int		prec;
	int		s_width;
	int		m_width;
};

typedef	struct s_flags t_flags;

void	fnd_width_n_prec(const char *str, t_flags *flags,va_list *args, bool prec);
size_t	ft_strlen(const char *s);
size_t	ft_putstr(char *s);
bool	ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*zeroes_str(int n);
int		ft_printf(const char *input, ...);
int		ft_check_flags(const char *str, va_list *args, int *count);
int		flag_init(const char *str, t_flags* flags);
int		ft_atoi(const char *str);
int		ft_chrFnd(const char *str, char c);
int		put_select(t_flags *flags, va_list *args);

//	print funcs

int		put_perc(t_flags *flags, va_list *args);
int		put_c(t_flags *flags, va_list *args);
int		put_s(t_flags *flags, va_list *args);
int		put_i(t_flags *flags, va_list *args);
//int		put_u(t_flags *flags, va_list *args);

#endif
