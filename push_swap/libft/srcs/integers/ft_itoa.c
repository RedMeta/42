/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:49:23 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/19 10:38:45 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;
	int		i;

	if (n < 0)
		nb = (long)n * -1;
	else
		nb = n;
	len = ft_numlen(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	i = len - 1;
	while (nb >= 10)
	{
		s[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	s[i] = nb + '0';
	s[len] = 0;
	return (s);
}
