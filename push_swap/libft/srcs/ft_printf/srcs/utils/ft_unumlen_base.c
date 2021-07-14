/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:19:15 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/26 14:19:58 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unumlen_base(unsigned int i, int base)
{
	int	n;

	n = (i != 0) * 0 + !(i != 0) * 1;
	while (i)
	{
		i /= base;
		n++;
	}
	return (n);
}