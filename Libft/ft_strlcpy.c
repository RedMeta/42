/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:29:31 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/16 15:29:36 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[j] && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize - j > 0)
		dst[j] = '\0';
	while (src[i])
		i++;
	return (i);
}
