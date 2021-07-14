/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:04:22 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/23 16:07:26 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_spec_initializer(char spec[9],
		int (*specifiers[8])(va_list *, t_modifiers))
{
	spec[0] = 'c';
	spec[1] = 's';
	spec[2] = 'd';
	spec[3] = 'i';
	spec[4] = 'p';
	spec[5] = 'u';
	spec[6] = 'x';
	spec[7] = 'X';
	spec[8] = 0;
	specifiers[0] = &ft_spec_c;
	specifiers[1] = &ft_spec_s;
	specifiers[2] = &ft_spec_d;
	specifiers[3] = &ft_spec_d;
	specifiers[4] = &ft_spec_p;
	specifiers[5] = &ft_spec_u;
	specifiers[6] = &ft_spec_x;
	specifiers[7] = &ft_spec_x;
	specifiers[8] = 0;
}

static int	ft_specifier_append(const char *format, int *i, va_list *args)
{
	char		specs[9];
	int			(*specifiers[9])(va_list *, t_modifiers);
	t_modifiers	modifiers;
	int			j;

	j = 0;
	ft_spec_initializer(specs, specifiers);
	ft_check_modifiers(args, format, i, &modifiers);
	if (format[*i] == '%')
	{
		(*i)++;
		return (ft_spec_r(modifiers));
	}
	while (specifiers[j])
	{
		if (format[*i] == specs[j])
		{
			(*i)++;
			if (j == 7)
				modifiers.upper_x = true;
			return (specifiers[j](args, modifiers));
		}
		j++;
	}
	return (-1);
}

static int	ft_printf_manager(const char *format, va_list *args, int n)
{
	int	i;
	int	ret;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret = ft_specifier_append(format, &i, args);
			if (ret < 0)
				return (-1);
			n += ret;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			n++;
		}
	}
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			n;

	va_start(args, format);
	n = ft_printf_manager(format, &args, 0);
	va_end(args);
	return (n);
}
