/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:57:37 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 15:24:28 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	initialize_counters(t_var *var)
{
	var->count.pa = 0;
	var->count.pb = 0;
	var->count.sa = 0;
	var->count.sb = 0;
	var->count.ss = 0;
	var->count.ra = 0;
	var->count.rb = 0;
	var->count.rr = 0;
	var->count.rra = 0;
	var->count.rrb = 0;
	var->count.rrr = 0;
}

void		initialize(t_var *var)
{
	var->args.ptr = 0;
	var->args.index = 0;
	var->args.min = 2147483647;
	var->args.max = -2147483648;
	var->lis.ptr = 0;
	var->lis.length = -1;
	var->stack_a = 0;
	var->stack_b = 0;
	var->info_a.len = 0;
	var->info_b.len = 0;
	var->info_a.min = 0;
	var->info_a.max = 0;
	var->info_a.pos_min = 0;
	var->info_a.pos_max = 0;
	var->moves.pos_in_a = 0;
	var->moves.pos_in_b = 0;
	var->moves.moves = 0;
	var->moves.directions = 0;
	var->flags.gui = 0;
	var->flags.verbose = 0;
	var->flags.counts = 0;
	initialize_counters(var);
}
