/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:53 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 15:18:19 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	m;
	unsigned int	i;

	str = (char *)b;
	m = (unsigned char)c;
	i = 0;
	while (i < len)
		str[i++] = m;
	return (b);
}
