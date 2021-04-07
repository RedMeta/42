/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:37:10 by asinamet          #+#    #+#             */
/*   Updated: 2021/03/25 15:37:12 by asinamet         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lung1;
	int		lung2;
	char	*str;

	if (s1 && s2)
	{
		lung1 = ft_strlen(s1);
		lung2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (lung1 + lung2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[lung1] = s2[i];
			lung1++;
		}
		str[lung1] = '\0';
		return (str);
	}
	return (NULL);
}