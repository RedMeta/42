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

static int	get_return_len(long long n, long long base)
{
	long long	len;

	len = 0;
	while (n >= base)
	{
		n /= base;
		++len;
	}
	return (len + 1);
}

static char	*itoa_base_loop(long long nb, long long base, char *str,
long long len, bool up)
{
	unsigned char	c;
	int				i;

	i = len - 1;
	
	while (nb > 0)
	{
		if (nb % base < 10)
			c = nb % base + 48;
		else
			c = nb % base + (87 * !up + 55 * up);
		str[i--] = c;
		nb = nb / base;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa_base(int n, long long base, bool up)
{
	char		*str;
	long long	nb;
	long long	len;

	if (n < 0)
		nb = (long long)(n * -1);
	else
		nb = (long long)n;
	len = (long long)get_return_len(nb, base);
	if (n < 0)
		str = (char *)malloc(sizeof(char) * (len + 1 + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		str[0] = '-';
		len++;
	}
	return (itoa_base_loop(nb, base, str, len, up));
}