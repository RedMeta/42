/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:04:14 by asinamet          #+#    #+#             */
/*   Updated: 2021/03/24 15:04:35 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_s(t_flags *flags, va_list *args)
{
	const char	*input;
	bool		u_pre;
	int			i;
	int			space;

	i = 0;
	input = va_arg(*args, const char *);
	u_pre = (flags->prec >= 0 && flags->prec <= (int )ft_strlen(input));
	flags->m_width = (ft_strlen(input) * !(u_pre) + (flags->prec * (u_pre)));				//---m_width is the lenght of the input string considering prec
	flags->s_width = flags->s_width * (flags->s_width >= flags->m_width)
		+ flags->m_width * (flags->s_width < flags->m_width);
	space = flags->s_width - flags->m_width;
	if (!flags->flags[1] && space)
	{
		while (space--)
			ft_putchar(' ');
	}
	while (i < flags->m_width)
		ft_putchar(input[i++]);
	if (flags->flags[1] && space)
	{
		while (space--)
			ft_putchar(' ');
	}
	return (flags->s_width);
}
