/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:16:31 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/25 17:45:19 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_c(va_list *args, t_modifiers modifiers)
{
	char	c;
	int		n;
	char	fill;

	c = va_arg(*args, int);
	n = 1;
	fill = modifiers.flags[zero] * '0' + !modifiers.flags[zero] * ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd(c, 1);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, 1);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd(c, 1);
	return (n);
}
