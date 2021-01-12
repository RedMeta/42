/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:50:19 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/12 15:52:01 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	c;
	char			*d;
	char			*s;
	char			mm[len];

	d = (char *)dst;
	s = (char *)src;
	c = 0;
	while (c < len)
	{
		mm[c] = s[c];
		c++;
	}
	c = 0;
	while (c < len)
	{
		d[c] = mm[c];
		c++;
	}
	return (dst);
}
