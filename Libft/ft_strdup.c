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

char	*ft_strdup(const char *s1)
{
	char		*new;
	size_t		size;
	size_t		s_size;

	size = 0;
	while (s1[size])
		++size;
	new = (void *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, (s_size = ft_strlen(s1)) + 1);
	new[s_size] = '\0';
	return (new);
}
