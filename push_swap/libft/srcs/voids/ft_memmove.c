/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:29:48 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/10 12:35:36 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (dst < src)
			((char *)dst)[i] = ((char *)src)[i];
		else
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}
