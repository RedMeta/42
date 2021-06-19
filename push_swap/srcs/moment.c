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
	int		c1;
	int		c2;
	int		inp[100];
	char	**list;

	c1 = c2 = 0;
	if (argc < 2)
		return (-1);
	else
	{
		if (!list_check(&argv[1], argc))
			return (-1);
		while(++c1 != argc)
		{
			list = ft_split(argv[c1], ' ');
			if (!list)
				return (-1);
			c2 += list_to_arr(list, &inp);
			printf("--/%d/--\n", inp[2]);
			//free(list);
		}
		if (!input_check(inp, c2))
		{
			printf("PIA%d\n", c2);
			return (-1);
		}
	}
	return (0);
}

int	list_check(char **list, int max)
{
	int x;
	int	y;

	x = y = 0;
	while (list[x] && (x != max))
	{
		while ((ft_isdigit(list[x][y]) || ft_isspace(list[x][y])) || (ft_issign(list[x][y]) &&
			(ft_issign(list[x][y + 1]) || ft_isdigit(list[x][y + 1]))))
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

int	list_to_arr(char **list, int (*res)[])
{
	static int	c = 0;
	int			c1;
	int			c2;

	c1 = c2 = 0;
	while (list[c1])
	{
		(*res)[c] = ft_atoi(list[c1]);
		printf("%d<---\n", (*res)[c]);
		c1++;		
	}
	return (c1);
}