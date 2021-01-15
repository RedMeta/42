/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:04:02 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/15 15:12:58 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	l;

	if (len > (l = ft_strlen(s + start)))
		new = ft_strdup((char *)(s + start));
	if (len < l && len != 0)
	{
		new = ft_strdup((char *)(s + start));
		new[len] = '\0';
		new = ft_strdup(new);
	}
	return (new);
}