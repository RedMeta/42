/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:55:59 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 12:59:22 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	c;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	c = 0;
	while (c < n)
		d[c++] = s[c];
	return (dst);
}
