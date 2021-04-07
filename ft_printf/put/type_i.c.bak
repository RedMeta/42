/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:40 by asinamet          #+#    #+#             */
/*   Updated: 2021/03/31 16:13:42 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static bool	help_f(char **str, t_flags *flags)
{
	bool	prec;
	bool	width;
	char	*seps;
	size_t	len;
	int		sep;
	

	len = ft_strlen(*str);
	prec = (flags->prec > (int )len);
	flags->m_width = flags->prec * (prec) + len * !(prec);
	width = (flags->s_width > flags->m_width);
	flags->s_width = flags->s_width * (width) + flags->m_width * !(width);
	flags->flags[0] =
		(((flags->prec < 0) || !(flags->flags[1])) && flags->flags[0]);
	sep = (flags->prec - len) * (prec);
	seps = zeroes_str(sep);
	if (seps)
	{
		*str = ft_strjoin(seps, *str);
		free(seps);
		return !(*str == NULL);
	}
	return (false);
}

int			put_i(t_flags *flags, va_list *args)
{
	char	*num;
	char	sep;
	bool	neg;
	int		conv;
	int		spcs;

	conv = va_arg(*args, int);
	neg = (conv < 0);
	if (neg)
		conv *= -1;
	num = ft_itoa(conv);
	if (!help_f(&num, flags))
		return -1;
	sep = ' ' * !(flags->flags[0]) + '0' * (flags->flags[0]);
	spcs = flags->s_width - (flags->m_width + neg);
	if (flags->flags[1])
	{
		if (neg)
			ft_putchar('-');
		ft_putstr(num);
	}
	while (spcs--)
		ft_putchar(sep);
	if (!flags->flags[1])
	{
		if (neg)
			ft_putchar('-');
		ft_putstr(num);
	}
	free(num);
	return (flags->s_width + neg);
}