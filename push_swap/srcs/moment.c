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
	int	
	int	*input;
	char **sep;

	c = 0;
	if (argc == 2)
	{
		sep = ft_split(argv[1], ' ');
		while (sep[c])
			c++;
		printf("---%d---\n", c);
		input = (int *)malloc(sizeof(int) * c);
		while (--c > -1)
			input[c] = ft_atoi(sep[c]);
		c = 0;
		while (input[c])
			printf("---%d---\n", input[c++]);
	}
	return (0);
}