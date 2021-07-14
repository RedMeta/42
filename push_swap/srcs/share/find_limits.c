/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 12:23:58 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 13:36:37 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	ft_init_limits(t_var *var, t_stack **cursor)
{
	var->info_a.min = 0;
	var->info_a.max = 0;
	var->info_a.pos_min = 0;
	var->info_a.pos_max = 0;
	*cursor = var->stack_a;
}

void		ft_find_stack_a_limits(t_var *var)
{
	t_stack	*cursor;
	int		i;

	ft_init_limits(var, &cursor);
	if (!cursor)
		return ;
	i = 0;
	var->info_a.min = cursor->n;
	var->info_a.max = cursor->n;
	cursor = cursor->next;
	while (cursor != var->stack_a)
	{
		i++;
		if (cursor->n > var->info_a.max)
		{
			var->info_a.max = cursor->n;
			var->info_a.pos_max = i;
		}
		if (cursor->n < var->info_a.min)
		{
			var->info_a.min = cursor->n;
			var->info_a.pos_min = i;
		}
		cursor = cursor->next;
	}
}
