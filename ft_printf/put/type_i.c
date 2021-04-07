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

static char	*init_input(va_list *args, bool *sign)
{
	int		input;
	char	*res;

	input = va_arg(*args, int);
	if (input < 0)
	{
		*sign = true;
		input *= -1;
	}
	res = ft_itoa(input);
	return (res);
}

static void	set_inp(char *str, t_flags *flags)
{
	bool	prec;
	bool	width;
	size_t	len;
	
	len = ft_strlen(str);
	prec = (flags->prec > len);
	flags->m_width = (flags->prec * (prec) + len * !(prec));
	width = (flags->s_width > flags->m_width);
	flags->s_width = flags->s_width * (width) + flags->m_width * !(width);
	flags->flags[0] = (((flags->prec < 0) || !(flags->flags[1])) && flags->flags[0]);
	return ;
}

int			put_i(t_flags *flags, va_list *args)
{
	char	*num;
	char	sep;
	bool	sign;						/*---[1] is negative, [0] is positive or 0---*/
	int		spcs;
	int		pr_spc;
	int		c;

	c = 0;
	num = init_input(args, &sign);
	set_inp(num, flags);
	sep = ' ' * !(flags->flags[0]) + '0' * (flags->flags[0]);
	spcs = flags->s_width - flags->m_width - sign;
	pr_spc = flags->prec - ft_strlen(num);

	if (flags->flags[1])
	{
		if (sign)
			ft_putchar('-');
		while (pr_spc-- > 0)
			ft_putchar('0');
		ft_putstr(num);
	}
	while (spcs > 0)
	{
		if (flags->flags[0])
			ft_putchar(sep);
	}
	if (!flags->flags[1])
	{
		if (sign)
			ft_putchar('-');
		while (pr_spc-- > 0)
			ft_putchar('0');
		ft_putstr(num);
	}
	free(num);
	return (flags->s_width);
}