/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:29:02 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/16 15:29:04 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	cc;
	unsigned char	*sq;

	cc = 0;
	sq = (unsigned char *)s;
	while (cc < n)
	{
		if (sq[cc] == (unsigned char)c)
			return (sq + cc);
		cc++;
	}
	return (NULL);
}
