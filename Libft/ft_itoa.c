/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:55:19 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/16 12:57:56 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_len(int n)
{
	long int	res;

	res = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char			*ft_itoa(int n)
{
	char		*res;
	long int	n2;
	int			c;
	int			sig;

	c = 0;
	sig = 1;
	if ((n2 = n) < 0)
	{
		n2 *= (sig *= -1);
		c += 1;
	}
	c += ft_itoa_len(n2);
	if (!(res = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	res[c] = '\0';
	while (--c != -1)
	{
		res[c] = (char)(48 + (n2 % 10));
		n2 /= 10;
	}
	if (sig == -1)
		res[0] = '-';
	return (res);
}
