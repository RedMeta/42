/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_loops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:46:17 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 13:38:30 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_same_str(t_var *var)
{
	while (var->moves.pos_in_a && var->moves.pos_in_b)
	{
		operation_double_rotate(var, PRINT);
		var->moves.pos_in_a--;
		var->moves.pos_in_b--;
	}
	while (var->moves.pos_in_b)
	{
		operation_rotate(var, B, PRINT, NO);
		var->moves.pos_in_b--;
	}
	while (var->moves.pos_in_a)
	{
		operation_rotate(var, A, PRINT, NO);
		var->moves.pos_in_a--;
	}
}

void	loop_same_rev(t_var *var)
{
	while ((var->info_b.len - var->moves.pos_in_b) &&
	(var->info_a.len - var->moves.pos_in_a))
	{
		operation_double_rev_rotate(var, PRINT);
		var->moves.pos_in_a++;
		var->moves.pos_in_b++;
	}
	while (var->info_b.len - var->moves.pos_in_b)
	{
		operation_rev_rotate(var, B, PRINT, NO);
		var->moves.pos_in_b++;
	}
	while (var->info_a.len - var->moves.pos_in_a)
	{
		operation_rev_rotate(var, A, PRINT, NO);
		var->moves.pos_in_a++;
	}
}

void	loop_diff_str(t_var *var)
{
	while (var->moves.pos_in_a)
	{
		operation_rotate(var, A, PRINT, NO);
		var->moves.pos_in_a--;
	}
	while (var->info_b.len - var->moves.pos_in_b)
	{
		operation_rev_rotate(var, B, PRINT, NO);
		var->moves.pos_in_b++;
	}
}

void	loop_diff_rev(t_var *var)
{
	while (var->info_a.len - var->moves.pos_in_a)
	{
		operation_rev_rotate(var, A, PRINT, NO);
		var->moves.pos_in_a++;
	}
	while (var->moves.pos_in_b)
	{
		operation_rotate(var, B, PRINT, NO);
		var->moves.pos_in_b--;
	}
}
