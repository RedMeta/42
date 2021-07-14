/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:43:07 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 16:52:22 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_a(t_var *var)
{
	while (var->stack_a->n != var->args.min)
	{
		if (var->info_a.pos_min > var->info_a.len / 2)
			operation_rev_rotate(var, A, PRINT, NO);
		else
			operation_rotate(var, A, PRINT, NO);
	}
}

static void	push_fastest(t_var *var)
{
	if (var->moves.directions == 0)
		loop_same_str(var);
	else if (var->moves.directions == 1)
		loop_same_rev(var);
	else if (var->moves.directions == 2)
		loop_diff_str(var);
	else if (var->moves.directions == 3)
		loop_diff_rev(var);
	operation_push_to_a(var, PRINT);
}

int			sort(t_var *var)
{
	t_stack		*cursor;
	t_moves		tmp;
	int			i;

	find_lis(var);
	while (var->stack_b)
	{
		i = 0;
		cursor = var->stack_b;
		var->moves = find_min_moves(var, cursor->n, i);
		i++;
		cursor = cursor->next;
		while (cursor != var->stack_b)
		{
			tmp = find_min_moves(var, cursor->n, i);
			if (tmp.moves < var->moves.moves)
				var->moves = tmp;
			i++;
			cursor = cursor->next;
		}
		push_fastest(var);
	}
	rotate_stack_a(var);
	exit_manager(var, NT, NOT_GNL_FREE);
	return (0);
}
