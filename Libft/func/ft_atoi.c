/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:13:24 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/12 15:21:43 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	num;
	int	n_p;

	num = 0;
	n_p = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n_p = -1;
		n_p = +1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (int)(*str - '0');
		str++;
	}
	return (num * n_p);
}
