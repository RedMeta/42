/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks_and_counts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:06:08 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 14:16:45 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

void		print_counts(t_var *var)
{
	ft_printf("Counts:\n\n");
	ft_printf("PA:  %-10d\n", var->count.pa);
	ft_printf("PB:  %-10d\n", var->count.pb);
	ft_printf("SA:  %-10d\n", var->count.sa);
	ft_printf("SB:  %-10d\n", var->count.sb);
	ft_printf("SS:  %-10d\n", var->count.ss);
	ft_printf("RA:  %-10d\n", var->count.ra);
	ft_printf("RB:  %-10d\n", var->count.rb);
	ft_printf("RR:  %-10d\n", var->count.rr);
	ft_printf("RRA: %-10d\n", var->count.rra);
	ft_printf("RRB: %-10d\n", var->count.rrb);
	ft_printf("RRR: %-10d\n\n", var->count.rrr);
}

static void	print_nt(int stack)
{
	if (stack == A)
		ft_printf("%15.d |", 0);
	else
		ft_printf(" %-15.d\n", 0);
}

static void	print_number(t_stack **cursor, int stack)
{
	if (stack == A)
		ft_printf("%15d |", (*cursor)->n);
	else
		ft_printf("%-15d\n", (*cursor)->n);
	(*cursor) = (*cursor)->next;
}

void		print_stacks(t_var *var)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	ft_printf("%15s | %-15s\n", "Stack A", "Stack B");
	cursor_a = var->stack_a;
	cursor_b = var->stack_b;
	if (cursor_a)
		print_number(&cursor_a, A);
	else
		print_nt(A);
	if (cursor_b)
		print_number(&cursor_b, B);
	else
		print_nt(B);
	while (cursor_a != var->stack_a || cursor_b != var->stack_b)
	{
		if (cursor_a && cursor_a != var->stack_a)
			print_number(&cursor_a, A);
		else
			print_nt(A);
		if (cursor_b && cursor_b != var->stack_b)
			print_number(&cursor_b, B);
		else
			print_nt(B);
	}
}
