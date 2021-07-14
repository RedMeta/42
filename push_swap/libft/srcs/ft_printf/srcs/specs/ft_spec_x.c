/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:32:58 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 10:46:48 by asinamet         ###   ########.fr       */
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

static int	ft_write_prec(unsigned int *i, int len, t_modifiers modifiers)
{
	int	n;

	n = 0;
	if (!(*i) && !modifiers.precision)
		return (n);
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', 1);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_spec_manager(unsigned int i, int n, t_modifiers modifiers)
{
	int	len;

	len = n;
	if (modifiers.flags[minus])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_putunbr_base_fd(i, (char *)modifiers.upper_x, 1);
	}
	n += ft_write_width((modifiers.precision > len) * modifiers.precision
			+ !(modifiers.precision > len) * len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_putunbr_base_fd(i, (char *)modifiers.upper_x, 1);
	}
	return (n);
}

int	ft_spec_x(va_list *args, t_modifiers modifiers)
{
	unsigned int	i;
	int				n;

	i = va_arg(*args, unsigned int);
	if (!modifiers.precision && !modifiers.width && !i)
		return (0);
	n = ft_unumlen_base(i, 16);
	if (!i && !modifiers.precision)
		n = 0;
	n = ft_spec_manager(i, n, modifiers);
	return (n);
}
