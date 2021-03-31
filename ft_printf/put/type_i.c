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

int	put_i(t_flags *flags, va_list *args)
{
	char	*num;
	int		c;

	num = ft_itoa(va_arg(*args, int));
	flags->m_width += 0;
	args +=0;
	return 1;
}