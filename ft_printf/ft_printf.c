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

int		flag_init(const char *str, t_flags *flags)
{
	int		c;

	c = 0;
	flags->flags[0] = false;
	flags->flags[1] = false;
	flags->m_width = -1;
	flags->s_width = -1;
	flags->prec = -1;
	flags->conv = -1;
	while (ft_chrFnd(CONV_FLAGS, str[++c]) != -1 || ft_chrFnd("123456789", str[c]) != -1)
	{
		if (str[c] == '-')
			flags->flags[1] = true;
		else if (!(str[c - 1] > '0' && str[c - 1] <= '9') && str[c] == '0')
			flags->flags[0] = true;
	}
 flags->conv = ft_chrFnd(CONV_TYPES, str[c]);
	if (flags->conv == -1)
		return -1;
	return c;
}

void	fnd_width_n_prec(const char *str, t_flags *flags, va_list *args, bool prec)			//---SETS WIDTH OR PREC
{
	int		c;
	int		num;

	num = 0;
	c = 0;
	while (!prec && ft_chrFnd("-0%%", str[c]) != -1 && (str[c] < '1' || str[c] >= '9'))
		c++;
	if (str[c] == '*')
		num = va_arg(*args, int);
	else if (str[c] >= '0' && str[c] <= '9')
		num = ft_atoi(str + c);
	if (prec)
		flags->prec = num;
	else
	{
		if (num < 0)
		{
			num = num * -1;
			flags->flags[1] = true;
		}
		flags->s_width = num;
	}
	return ;
}

int		ft_check_flags(const char *str, va_list *args, int *count)			//---PARENT FLAG CHECKER AND ADJUST---
{
	int		skip;
	int		c;
	t_flags	flags;

	skip = 0;
	c = 0;
	if ((skip = flag_init(str, &flags)) == -1)
		return (0);
	fnd_width_n_prec(str, &flags, args, false);
	while (ft_chrFnd("-.*0123456789", str[++c]) != -1)
	{
		if (str[c] == '.')
			fnd_width_n_prec(str + c + 1, &flags, args, true);
	}
	*count += put_select(&flags, args);
	return skip;
}


int		ft_printf(const char *input, ...)					//---INIT VARG AND CHECK INPUT---
{
	int		res;
	int		c1;
	va_list	args;

	va_start(args, input);
	c1 = -1;
	res = 0;
	while (input[++c1])
	{
		if (input[c1] != '%')
		{
			ft_putchar(*(input + c1));
			res++;
		}
		else
			c1 = c1 + ft_check_flags((input + c1), &args, &res);
	}
	va_end (args);
	return res;
}
