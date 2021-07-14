/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:56:30 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 12:43:47 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	if_print(t_var *var)
{
	if (var->flags.gui || var->flags.verbose)
	{
		if (var->flags.gui)
			print_fake_gui(var);
		else
			print_stacks(var);
		ft_printf("\n");
	}
}

static void	add_to_stack(t_stack **stack, t_stack *tmp)
{
	tmp->previous = (*stack)->previous;
	tmp->next = (*stack);
	(*stack)->previous->next = tmp;
	(*stack)->previous = tmp;
	*stack = tmp;
}

void		operation_push_to_b(t_var *var, int print)
{
	t_stack	*tmp;

	if (!var->stack_a)
		return ;
	tmp = var->stack_a;
	var->stack_a->next->previous = tmp->previous;
	var->stack_a->previous->next = tmp->next;
	var->stack_a = tmp->next;
	if (!var->stack_b)
	{
		var->stack_b = tmp;
		tmp->previous = tmp;
		tmp->next = tmp;
	}
	else
		add_to_stack(&var->stack_b, tmp);
	var->info_a.len--;
	var->info_b.len++;
	if (!var->info_a.len)
		var->stack_a = 0;
	if (print)
		ft_printf("pb\n");
	if_print(var);
	var->count.pb++;
	ft_find_stack_a_limits(var);
}

void		operation_push_to_a(t_var *var, int print)
{
	t_stack	*tmp;

	if (!var->stack_b)
		return ;
	tmp = var->stack_b;
	var->stack_b->next->previous = tmp->previous;
	var->stack_b->previous->next = tmp->next;
	var->stack_b = tmp->next;
	if (!var->stack_a)
	{
		var->stack_a = tmp;
		tmp->previous = tmp;
		tmp->next = tmp;
	}
	else
		add_to_stack(&var->stack_a, tmp);
	var->info_a.len++;
	var->info_b.len--;
	if (!var->info_b.len)
		var->stack_b = 0;
	if (print)
		ft_printf("pa\n");
	if_print(var);
	var->count.pa++;
	ft_find_stack_a_limits(var);
}
