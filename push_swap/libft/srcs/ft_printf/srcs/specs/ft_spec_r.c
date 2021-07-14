/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:55:45 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/25 17:45:23 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_r(t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 1;
	fill = modifiers.flags[zero] * '0' + !modifiers.flags[zero] * ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd('%', 1);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, 1);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd('%', 1);
	return (n);
}
