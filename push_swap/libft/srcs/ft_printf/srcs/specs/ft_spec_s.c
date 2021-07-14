/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:27:53 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/25 17:45:25 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_s(va_list *args, t_modifiers modifiers)
{
	char	*s;
	int		len;
	int		n;
	char	fill;

	s = va_arg(*args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	fill = modifiers.flags[zero] * '0' + !modifiers.flags[zero] * ' ';
	if (modifiers.precision > -1)
		len = (modifiers.precision > len) * len + !(
				modifiers.precision > len) * modifiers.precision;
	n = len;
	if (modifiers.flags[minus])
		ft_putstrlen_fd(s, len, 1);
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, 1);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putstrlen_fd(s, len, 1);
	return (n);
}
