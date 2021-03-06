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

#include "../ft_printf.h"

int	put_perc(t_flags *flags, va_list *args)
{
	int		c;
	bool	is_zero;
	char	space;

	flags->m_width = 1;
	c = 1;
	is_zero = (flags->flags[0] && !flags->flags[1]);
	space = '0' * (is_zero) + ' ' * !(is_zero);
	if (flags->s_width > flags->m_width)
	{
		c = flags->s_width;
		if (flags->flags[1])
		{
			ft_putchar('%');
			flags->s_width--;
		}
		while (flags->s_width-- > 1)
			ft_putchar(space);
		ft_putchar(space * (flags->flags[1]) + '%' * !(flags->flags[1]));
	}
	else
		ft_putchar('%');
	args += 0;
	return (c);
}