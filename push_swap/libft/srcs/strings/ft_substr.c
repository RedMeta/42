/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:59 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 17:51:38 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!len || start >= slen)
		return (ft_strdup(""));
	if (slen - start > len)
		sublen = len;
	else
		sublen = slen - start;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
