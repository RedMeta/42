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

	c = 1;
	flags->flags[0] = false;
	flags->flags[1] = false;
	flags->m_width = -1;
	flags->s_width = -1;
	flags->prec = -1;
	while (str[c] != '\0' && ft_chrFnd(CONV_TYPES, str[c]) == -1)
	{
		if (str[c] == '-')
			flags->flags[1] = true;
		else if (str[c] == '0' && !(str[c - 1] > '0' && str[c - 1] <= '9'))
			flags->flags[0] = true;
		c++;
	}
	flags->conv = str[c];
//	write(1, &flags->conv, 1);				// TEST FOR CHECK FLAGS
	return c;
}

bool	fnd_width_n_prec(const char *str, t_flags *flags, va_list *args, int max)			//---SETS WIDTH OR PREC
{
	bool	prec;
	int		c;
	int		num;

	prec = false;
	c = -1;
	while (++c <= max)
	{
		if (str[c] == '.')
			prec = true;
	}
	if (str[c] == '*')
		num = va_arg(*args, int);
	else if (str[c] >= '1' && str[c] <= '9')
		num = ft_atoi(str + c);
	if (prec)
		flags->prec = num;
	else
	{
		printf("%d", num);
		if (num < 0)
		{
			num *= -1;
			flags->flags[1] = true;
		}
		flags->s_width = num;
	}
	return (prec);
}

int		ft_check_flags(const char *str, va_list *args, int *count)			//---PARENT FLAG CHECKER AND ADJUST---
{
	int		skip;
	t_flags	flags;

	skip = 0;
	skip = flag_init(str, &flags);
	if (!fnd_width_n_prec(str, &flags, args, skip))
	{
		while (*str == '.' || *str == flags.conv)
			str++;
		if (*str == '.')
			fnd_width_n_prec(str, &flags, args, skip);
	}
	while (args || count)
		break;
	//printf("%d\n", flags.s_width);
	return skip;
}

int		ft_printf(const char *input, ...)			//---INIT VARG AND CHECK INPUT---
{
	int	res;
	int	c;
	const char		*read;
	va_list			args;
	va_start(args, input);

	res = c = 0;
	read = input;
	while (*read != '\0')
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
			printf("---%d---", c);					//test jump
		}
		read++;
	}
	va_end (args);
	return res;
}
