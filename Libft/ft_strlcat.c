/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:31:45 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/15 12:31:52 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
	{
		++i;
		++dst;
	}
	while (*src && i + 1 < dstsize)
	{
		*dst = *src;
		++dst;
		++src;
		++i;
	}
	if (i < dstsize)
		*dst = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}
