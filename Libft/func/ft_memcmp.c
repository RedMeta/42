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

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	cc;
	unsigned char	*s1;
	unsigned char	*s2;

	cc = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (cc < n && s1[cc] == s2[cc])
		cc++;
	return ((int)(s1[cc] - s2[cc]));
}
