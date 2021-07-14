/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:07:55 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 17:18:07 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(t_var *var)
{
	t_stack		*cursor;

	if (!var->stack_a || var->stack_b)
		return (0);
	cursor = var->stack_a;
	if (cursor->n > cursor->next->n)
		return (0);
	cursor = cursor->next;
	while (cursor->next != var->stack_a)
	{
		if (cursor->n > cursor->next->n)
			return (0);
		cursor = cursor->next;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_var	var;

	initialize(&var);
	take_numbers(&var, argc, argv);
	if (check(&var))
		return (0);
	if (var.info_a.len <= 5)
		return (sort_less_five(&var));
	return (sort(&var));
}
