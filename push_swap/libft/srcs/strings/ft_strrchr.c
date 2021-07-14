/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:53:41 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/10 13:10:06 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)s[0] == (char)c)
		return ((char *)(s + i));
	return (0);
}
