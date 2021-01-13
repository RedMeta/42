/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:13:00 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 14:19:15 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	cc;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	cc = 0;
	while (cc < n)
	{
		d[cc] = s[cc];
		if ((char)c == s[cc])
			break ;
		cc++;
	}
	return (dst);
}
