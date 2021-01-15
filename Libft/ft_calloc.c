/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:30:24 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/14 17:30:31 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		res = NULL;
		return (res);
	}
	res = (void *)malloc(size * count);
	while (i <= count)
	{
		((char*)res)[i] = 0;
		i++;
	}
	return (res);
}
