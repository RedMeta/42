/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:38:46 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 17:16:40 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *s2)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1);
	while (s1[start] && is_in_charset(s1[start], (char *)s2))
		start++;
	while (end > start && is_in_charset(s1[end - 1], (char *)s2))
		end--;
	s = (char *)malloc((end - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (start < end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
