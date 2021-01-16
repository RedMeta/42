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
