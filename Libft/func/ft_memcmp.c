/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:37:32 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/13 13:38:43 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	cc;
	unsigned char	*sp1;
	unsigned char	*sp2;

	cc = 0;
	sp1 = (unsigned char *)s1;
	sp2 = (unsigned char *)s2;
	while (cc < n && sp1[cc] == sp2[cc])
		cc++;
	if (cc == n)
		return (0);
	return (sp1[cc] - sp2[cc]);
}
