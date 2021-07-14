/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:39:32 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 15:19:08 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

int		find_index(t_var *var, int n)
{
	int i;

	i = 0;
	while (i < var->args.len)
	{
		if (var->args.index[i] == n)
			break ;
		i++;
	}
	return (i + 1);
}

void	index_stack(t_var *var)
{
	int i;
	int j;

	i = 0;
	var->args.index = (int *)malloc(var->args.len * sizeof(int));
	while (i < var->args.len)
	{
		var->args.index[i] = var->args.ptr[i];
		i++;
	}
	i = 0;
	while (i < var->args.len)
	{
		j = i + 1;
		while (j < var->args.len)
		{
			if (var->args.index[i] > var->args.index[j])
				ft_swap(&var->args.index[i], &var->args.index[j]);
			j++;
		}
		i++;
	}
}
