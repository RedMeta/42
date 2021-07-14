/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:57:23 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 13:38:03 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_var *var)
{
	if (var->info_a.pos_max == 0)
		operation_rotate(var, A, PRINT, NO);
	if (var->info_a.pos_max == 1)
		operation_rev_rotate(var, A, PRINT, NO);
	if (var->info_a.pos_max == 2 && var->info_a.pos_min)
		operation_swap(var, A, PRINT, NO);
}

static void	sort_four(t_var *var)
{
	while (var->info_a.pos_min != 0 && var->info_a.pos_max)
	{
		if (var->info_a.pos_min < (var->info_a.len - var->info_a.pos_min))
			operation_rotate(var, A, PRINT, NO);
		else
			operation_rev_rotate(var, A, PRINT, NO);
	}
	operation_push_to_b(var, PRINT);
	sort_three(var);
	operation_push_to_a(var, PRINT);
	if (var->info_a.pos_max == 0)
		operation_rotate(var, A, PRINT, NO);
}

static void	sort_five(t_var *var)
{
	while (var->info_a.pos_min != 0 && var->info_a.pos_max)
	{
		if (var->info_a.pos_min < (var->info_a.len - var->info_a.pos_min))
			operation_rotate(var, A, PRINT, NO);
		else
			operation_rev_rotate(var, A, PRINT, NO);
	}
	operation_push_to_b(var, PRINT);
	sort_four(var);
	operation_push_to_a(var, PRINT);
	if (var->info_a.pos_max == 0)
		operation_rotate(var, A, PRINT, NO);
}

int			sort_less_five(t_var *var)
{
	ft_find_stack_a_limits(var);
	if (var->info_a.len == 2)
		operation_swap(var, A, PRINT, NO);
	else if (var->info_a.len == 3)
		sort_three(var);
	else if (var->info_a.len == 4)
		sort_four(var);
	else if (var->info_a.len == 5)
		sort_five(var);
	exit_manager(var, NT, NOT_GNL_FREE);
	return (0);
}
