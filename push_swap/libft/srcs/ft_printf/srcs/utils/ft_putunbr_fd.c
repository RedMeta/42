/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:51:22 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/25 14:10:32 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	print;

	if (!fd)
		return ;
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
	else
	{
		print = n + '0';
		write(fd, &print, 1);
	}
}
