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

void	ft_check_flags(char *str, va_list args)
{
	
}

int		ft_printf(const char *input, ...)
{
	unsigned int	res;
	const char		*read;
	va_list			args;
	va_start(args, input);

	res = 0;
	read = input;
	while (*read != '\0')
	{
		if (*read != '%')
		{
			ft_putchar(*read++);
			res++;
		}
		else
			ft_check_flags(read, args);
	}
	va_end (args);
	return res;
}