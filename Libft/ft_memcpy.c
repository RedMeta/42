/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:55:59 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/13 14:52:48 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	c;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	c = 0;
	while (c < n)
	{
		d[c] = s[c];
		c++;
	}
	return (dst);
}
