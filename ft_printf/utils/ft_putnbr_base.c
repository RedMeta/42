/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:25:46 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 15:25:49 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int	n_to_p(int n)
{
	char			s;
	unsigned int	u_n;

	s = '-';
	if (n == -2147483648)
		u_n = (unsigned int)(-1 * n);
	else if (n < 0)
	{
		u_n = (unsigned int)(-1 * n);
		write(1, &s, 1);
	}
	else
		u_n = (unsigned int)n;
	return (u_n);
}

static int			ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (*(c + i) != '\0')
		i++;
	return (i);
}

static int			base_check(char *base)
{
	int	c1;
	int	c2;

	c1 = 0;
	if (ft_strlen(base) > 1)
	{
		while (base[c1] != '\0' && base[c1] != '-' && base[c1] != '+')
		{
			c2 = c1 + 1;
			while (base[c1] != base[c2] && base[c2] != '\0' && base[c1] != '\0')
				c2++;
			if (base[c2] != '\0')
				return (1);
			c1++;
		}
		if (base[c1] == '\0')
			return (0);
	}
	return (1);
}

void			ft_putnbr_base(int n, char *base)
{
	int	d;
	int	r;
	int	len_base;

	len_base = ft_strlen(base);
	if (!base_check(base))
	{
		n = n_to_p(n);
		r = (n % (len_base));
		d = (n / (len_base));
		if (d != 0)
			ft_putnbr_base(d, base);
		write(1, (base + r), 1);
	}
}
