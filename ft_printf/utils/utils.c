/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:23:07 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 14:23:09 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_putchar(char c)
{
		write(1, &c, 1);
}

int	ft_chrFnd(const char *str, char c)
{
	int i;
	i = 0;
	while ((str[i] != c) && str[i])
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

void	flag_init(const char *str, s_flags* flags)
{
	int		c;

	c = 0;
	flags->fill = ' ';
	flags->m_width = 0;
	flags->s_width = 0;
	flags->side = 0;
	flags->dot = -1;
	while (!ft_chrFnd(CONV_TYPES, str[c]) && str[c])
		c++;
	flags->conv = str[c];
	write(1, &flags->conv, 1);
}