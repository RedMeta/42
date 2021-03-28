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
#include <stdio.h>

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
	printf("+++%d+++", flags->conv);
	while (ft_chrFnd(CONV_FLAGS, str[++c]) != -1 || ft_chrFnd("123456789", str[c] != -1))
	{
		if (str[c] == '-')
			flags->flags[1] = true;
		else if (!(str[c - 1] > '0' && str[c - 1] <= '9') && str[c] == '0')
			flags->flags[0] = true;
		flags->conv = ft_chrFnd(CONV_TYPES, str[c]);
	}
	if (flags->conv == -1)
		c = -1;
	return c;
}

bool	fnd_width_n_prec(const char *str, t_flags *flags, va_list *args, bool prec)			//---SETS WIDTH OR PREC
{
	int		c;
	int		num;

	num = -1;
	c = 0;
	if (str[c] == '*')
		num = va_arg(*args, int);
	else if (str[c] >= '0' && str[c] <= '9')
		num = ft_atoi(str + c);
	if (prec && num)
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
	return (prec);
}

int		ft_check_flags(const char *str, va_list *args, int *count)			//---PARENT FLAG CHECKER AND ADJUST---
{
	int		skip;
	int		c;
	bool	prec;
	t_flags	flags;

	skip = -1;
	c = 0;
	prec = false;
	if ((skip = flag_init(str, &flags)) == -1)
		return (0);
	while (str[++c] != '\0' && !ft_isalpha((int) str[c]) && str[c] != '%' && !prec)
	{
		if (str[c] == '.')
		{
			prec = true;
			c++;
		}
		if (str[c] == '*' || (str[c] >= '0' && str[c] <= '9'))
			fnd_width_n_prec((str + c), &flags, args, prec);
	}
	*count += put_select(&flags, args);
	return skip;
}

int		ft_printf(const char *input, ...)
{														//---INIT VARG AND CHECK INPUT---
	int	res;
	int	c;
	const char		*read;
	va_list			args;
	va_start(args, input);

	res = c = 0;
	read = input;
	while (*read)
	{
		if (*read != '%')
		{
			ft_putchar(*read);
			res++;
		}
		else
		{
			c = ft_check_flags(read, &args, &res);
			read = read + c;
		}
		read++;
	}
	va_end (args);
	return res;
}
