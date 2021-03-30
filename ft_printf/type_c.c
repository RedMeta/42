/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:03:40 by asinamet          #+#    #+#             */
/*   Updated: 2021/03/21 14:03:42 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_c(t_flags *flags, va_list *args)
{
	char	res;
	int		c;

	flags->m_width = c = 1;
	res = (char)va_arg(*args, int);
	if (flags->s_width > flags->m_width)
	{
		c = flags->s_width;
		if (flags->flags[1])
		{
			ft_putchar(res);
			flags->s_width--;
		}
		while (flags->s_width-- > 1)
			ft_putchar(' ');
		ft_putchar((' ' * (flags->flags[1]) + res * !(flags->flags[1])));
	}
	else
		ft_putchar(res);
	return (c);
}