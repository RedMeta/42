/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:04:00 by asinamet          #+#    #+#             */
/*   Updated: 2021/03/21 14:04:01 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (nbr < 0)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr * sign);
}

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
	long int	n2;
	char		*res;
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
	res = (char *)malloc(sizeof(char) * (c + 1));
	if (!res)
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
