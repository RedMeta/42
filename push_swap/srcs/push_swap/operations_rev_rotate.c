/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:56:34 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 12:50:03 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	if_print(t_var *var, int from_double)
{
	if (from_double)
		return ;
	if (var->flags.gui || var->flags.verbose)
	{
		if (var->flags.gui)
			print_fake_gui(var);
		else
			print_stacks(var);
		ft_printf("\n");
	}
}

void		operation_rev_rotate(t_var *var, int a_or_b,
			int print, int from_double)
{
	t_stack	**stack;

	stack = a_or_b ? &var->stack_b : &var->stack_a;
	if (!(*stack))
		return ;
	*stack = (*stack)->previous;
	if (print)
	{
		if (a_or_b == A)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
	if_print(var, from_double);
	if (!from_double && a_or_b == A)
		var->count.rra++;
	else if (!from_double)
		var->count.rrb++;
	ft_find_stack_a_limits(var);
}

void		operation_double_rev_rotate(t_var *var, int print)
{
	if (var->stack_a)
		operation_rev_rotate(var, A, NOT_PRINT, YES);
	if (var->stack_b)
		operation_rev_rotate(var, B, NOT_PRINT, YES);
	if (print)
		ft_printf("rrr\n");
	if_print(var, NO);
	var->count.rrr++;
}
