/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:58:51 by asinamet          #+#    #+#             */
/*   Updated: 2020/10/28 18:10:02 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_to_p(int n)
{
	char s;

	s = '-';
	if (n < 0)
	{
		n = -n;
		write(1, &s, 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		d;
	int		r;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = n_to_p(n);
	r = (n % (10));
	d = (n / (10));
	if (d != 0)
	{
		ft_putnbr_fd(d, fd);
	}
	c = '0' + r;
	write(fd, &c, 1);
	return ;
}
