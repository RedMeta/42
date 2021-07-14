/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:21:57 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 10:47:07 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_width(int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	fill = modifiers.flags[zero] * '0' + !modifiers.flags[zero] * ' ';
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, 1);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(int len, t_modifiers modifiers)
{
	int	n;

	n = 0;
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', 1);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_spec_manager(unsigned long i, int n, t_modifiers modifiers)
{
	int	len;

	len = n;
	if (modifiers.flags[minus])
	{
		ft_putstr_fd("0x", 1);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || i)
			ft_putunbr_base_fd(i, "0123456789abcdef", 1);
	}
	n += ft_write_width((modifiers.precision > len) * modifiers.precision + !(
				modifiers.precision > len) * len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		ft_putstr_fd("0x", 1);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || i)
			ft_putunbr_base_fd(i, "0123456789abcdef", 1);
	}
	return (n);
}

int	ft_spec_p(va_list *args, t_modifiers modifiers)
{
	unsigned long	i;
	int				n;

	i = (unsigned long)va_arg(*args, void *);
	n = ft_ulnumlen_base(i, 16) + 2;
	if (!modifiers.precision && !i)
		n = 2;
	n = ft_spec_manager(i, n, modifiers);
	return (n);
}
