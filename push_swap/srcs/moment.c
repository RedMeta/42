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
	int	c;
	int	total;
	int	*input;
	char **sep;

	c = 0;
	if (argc == 2)
	{
		sep = ft_split(argv[1], ' ');
		while (sep[c])
			c++;
		total = c;
		printf("---%d---\n", total);
		input = (int *)malloc(sizeof(int) * total);
		while (--c > -1)
			input[c] = ft_atoi(sep[c]);
		while (++c < total)
			printf("---%d---\n", input[c]);
	}
	return (0);
}