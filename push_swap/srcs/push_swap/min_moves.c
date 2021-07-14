/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:15:26 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 16:42:28 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_moves		save_min_moves(int pos_in_a, int pos_in_b, t_info_moves tmp)
{
	t_moves	moves;

	moves.pos_in_b = pos_in_b;
	moves.pos_in_a = pos_in_a;
	moves.moves = tmp.same.moves < tmp.diff.moves ?
	tmp.same.moves : tmp.diff.moves;
	moves.directions = tmp.same.moves < tmp.diff.moves ?
	tmp.same.directions : tmp.diff.directions;
	return (moves);
}

static t_info_moves	compare_min_moves(t_info_moves tmp)
{
	if (tmp.moves_same_str < tmp.moves_same_rev)
	{
		tmp.same.directions = 0;
		tmp.same.moves = tmp.moves_same_str;
	}
	else
	{
		tmp.same.directions = 1;
		tmp.same.moves = tmp.moves_same_rev;
	}
	if (tmp.moves_diff_str < tmp.moves_diff_rev)
	{
		tmp.diff.directions = 2;
		tmp.diff.moves = tmp.moves_diff_str;
	}
	else
	{
		tmp.diff.directions = 3;
		tmp.diff.moves = tmp.moves_diff_rev;
	}
	return (tmp);
}

static t_moves		calculate_min_moves(t_var *var, int pos_in_a, int pos_in_b)
{
	t_moves			moves;
	t_info_moves	tmp;

	tmp.moves_same_str = pos_in_b > pos_in_a ? pos_in_b : pos_in_a;
	tmp.moves_same_rev = (var->info_b.len - pos_in_b) >
	(var->info_a.len - pos_in_a) ?
	(var->info_b.len - pos_in_b) : (var->info_a.len - pos_in_a);
	tmp.moves_diff_str = (var->info_b.len - pos_in_b) + pos_in_a;
	tmp.moves_diff_rev = pos_in_b + (var->info_a.len - pos_in_a);
	tmp = compare_min_moves(tmp);
	moves = save_min_moves(pos_in_a, pos_in_b, tmp);
	return (moves);
}

static int			find_pos_in_a(t_var *var, int n)
{
	t_stack	*cursor;
	int		pos_in_a;

	pos_in_a = 0;
	cursor = var->stack_a;
	if (n < cursor->n && n > cursor->previous->n)
		(void)cursor;
	else
	{
		pos_in_a++;
		cursor = cursor->next;
	}
	while (cursor != var->stack_a)
	{
		if (n < cursor->n && n > cursor->previous->n)
			break ;
		pos_in_a++;
		cursor = cursor->next;
	}
	return (pos_in_a);
}

t_moves				find_min_moves(t_var *var, int n, int pos_in_b)
{
	t_moves	moves;
	int		pos_in_a;

	pos_in_a = find_pos_in_a(var, n);
	moves = calculate_min_moves(var, pos_in_a, pos_in_b);
	return (moves);
}
