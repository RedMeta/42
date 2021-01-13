/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:48:59 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/13 10:51:41 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned int	cc;
	unsigned char	*s;

	cc = 0;
	s = (unsigned char *)str;
	while (cc < n)
	{
		if (s[cc] == (unsigned char)c)
			return (s + cc);
		cc++;
	}
	return (NULL);
}
