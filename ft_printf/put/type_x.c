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
	res = ft_itoa_base(input, 16, false);
	if (res[0] == 0)
		res[0] = '0';
	return (res);
}

static void	set_inp(char *str, t_flags *flags)
{
	bool	prec;
	bool	width;
	size_t	len;
	
	len = ft_strlen(str);
	prec = (flags->prec > (int)len);
	flags->m_width = ((flags->prec * (prec) + len * !(prec)));
	if (flags->prec == 0 && str[0] == '0')
	{
		str[0] = 0;
		flags->m_width = 0;
	}
	width = (flags->s_width > flags->m_width);
	flags->s_width = flags->s_width * (width) + flags->m_width * !(width);
	flags->flags[0] = ((flags->prec < 0 && !(flags->flags[1])) && flags->flags[0]);

	return ;
}

int			put_x(t_flags *flags, va_list *args)
{
	bool	sign;														/*---[1] is negative, [0] is positive or 0---*/
	char	*num;
	char	sep;
	int		fill;
	int		pr_spc;
	int		c;

	c = 0;
	num = init_input(args, &sign);
	set_inp(num, flags);
	sep = ' ' * (!flags->flags[0] || flags->flags[1]) +
		'0' * (flags->flags[0] && !flags->flags[1]);			/*---Branchless conditional for choosing separator---*/
	fill = flags->s_width - flags->m_width - sign;
	pr_spc = (flags->prec - ft_strlen(num)) *
					(flags->prec == flags->m_width);

	if (!flags->flags[1])
	{
		if (sep == '0' && sign)
		{
			c += ft_putchar('-');
		}
		while (fill-- > 0)
			c += ft_putchar(sep);
	}
	if (sep != '0' && sign)
		c += ft_putchar('-');
	while (pr_spc-- > 0)
		c += ft_putchar('0');
	c += ft_putstr(num);
	if (flags->flags[1])
	{
		while (fill-- > 0)
			c += ft_putchar(sep);
	}
	free(num);
	return (c);
}