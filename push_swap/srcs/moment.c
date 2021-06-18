/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:45:54 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/17 12:45:56 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	init(int argc, char **argv)
{
	int		c;
	int		max;
	int		*inp;
	char	**sep;

	if (argc < 2)
		return (-1);
	c = 0;
	if (argc == 2)
	{
		sep = ft_split(argv[1], ' ');
		max = 0;
		while (sep[max])
		{
			max++;
		}
	}
	else
	{
		sep = &argv[1];
		max = argc - 1;
	}
	if (list_check(sep, c, max))
	{
		if (list_to_arr(sep, max, &inp))
			return (1);
	}
	return (0);
}

int	list_check(char **list, int x, int max)
{
	int	y;

	y = 0;
	while (list[x] && (x != max))
	{
		while (ft_isdigit(list[x][y]) || ft_isspace(list[x][y]))
			y++;
		if (list[x][y] != '\0')
			return (0);
		y = 0;
		x++;
	}
	return (1);
}

int	input_check(int *input, int size)
{
	int	c;
	int d;

	c = 0;
	while (c != size)
	{
		d = c + 1;
		while (d != size)
		{
			if (input[c] == input[d])
				return (0);
			d++;
		}
		c++;
	}
	return (1);
}

int	list_to_arr(char **sep, int count, int **res)
{
	int	c;

	c = 0;
	*res = (int *)malloc(sizeof(int) * count);
	if (!res)
		return (-1);
	while (c != count)
	{
		(*res)[c] = ft_atoi(sep[c]);
		printf("%d<---\n", (*res)[c]);
		c++;		
	}
	if (input_check(*res, count))
		return (1);
	return (0);
}