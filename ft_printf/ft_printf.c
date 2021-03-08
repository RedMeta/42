/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:42:23 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 13:42:27 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(const char *str, va_list args, int count)
{

	s_flags	*p_flags;
	p_flags = &flags;
	flag_init(str, p_flags);
	while (args || count)
		break;
}

int		ft_printf(const char *input, ...)
{
	unsigned int	res;
	unsigned int	c;
	const char		*read;
	va_list			args;
	va_start(args, input);

	res = c = 0;
	read = input;
	while (read[c] != '\0')
	{
		if (read[c] != '%')
		{
			ft_putchar(read[c++]);
			res++;
		}
		else
			ft_check_flags(read + ++c, args, res);
	}
	va_end (args);
	return res;
}