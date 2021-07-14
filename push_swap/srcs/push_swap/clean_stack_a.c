/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:28:18 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 16:44:43 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_in_lis(t_var *var, int n)
{
	int	i;

	i = 0;
	while (i < var->lis.length)
	{
		if (var->lis.ptr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void		clean_stack_a(t_var *var)
{
	while (var->info_a.len != var->lis.length)
	{
		if (!ft_is_in_lis(var, var->stack_a->n))
		{
			operation_push_to_b(var, PRINT);
			if (var->stack_b->n == var->args.min ||
			var->stack_b->n == var->args.max)
				operation_rotate(var, B, PRINT, NO);
		}
		else
			operation_rotate(var, A, PRINT, NO);
	}
	while (var->stack_b->previous->n == var->args.min ||
	var->stack_b->previous->n == var->args.max)
	{
		operation_rev_rotate(var, B, PRINT, NO);
		operation_push_to_a(var, PRINT);
		if (var->stack_a->n == var->args.max)
			operation_rotate(var, A, PRINT, NO);
	}
}
