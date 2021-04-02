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

#include "../ft_printf.h"

static void	put_space(int *space, bool sep)
{		
	while (*space)
	{
		ft_putchar(' ' * !(sep) + '0'* (sep));
		*space -= 1;
	}
}

int		put_s(t_flags *flags, va_list *args)
{
	const char	*input;
	bool		prec;
	int			i;
	int			space;

	i = 0;
	input = va_arg(*args, const char *);
	if (!input)
		input = "(null)";
	prec = (flags->prec >= 0 && flags->prec < (int )ft_strlen(input));
	flags->m_width = (ft_strlen(input) * !(prec) + (flags->prec * (prec)));				//---m_width is the lenght of the input string considering prec
	flags->s_width = flags->s_width * (flags->s_width >= flags->m_width)
		+ flags->m_width * (flags->s_width < flags->m_width);
	space = flags->s_width - flags->m_width;
	if (!flags->flags[1] && space)
		put_space(&space, (!prec && flags->flags[0]));
	while (i < flags->m_width)
		ft_putchar(input[i++]);
	if (flags->flags[1] && space)
		put_space(&space, false);
	return (flags->s_width);
}
