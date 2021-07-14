/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:51:42 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/25 13:55:17 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_special_atoi(const char *s, int *i)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(s[*i]))
	{
		ret = ret * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (ret);
}
