/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:56:39 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 12:44:04 by asinamet         ###   ########.fr       */
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

void		operation_swap(t_var *var, int a_or_b, int print, int from_double)
{
	t_stack	**stack;
	int		tmp;

	stack = a_or_b ? &var->stack_b : &var->stack_a;
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
	if (print)
	{
		if (a_or_b == A)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	if_print(var, from_double);
	if (!from_double && a_or_b == A)
		var->count.sa++;
	else if (!from_double)
		var->count.sb++;
	ft_find_stack_a_limits(var);
}

void		operation_double_swap(t_var *var, int print)
{
	if (var->stack_a)
		operation_swap(var, A, NOT_PRINT, YES);
	if (var->stack_b)
		operation_swap(var, B, NOT_PRINT, YES);
	if (print)
		ft_printf("ss\n");
	if_print(var, NO);
	var->count.ss++;
}
