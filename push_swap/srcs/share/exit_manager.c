/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:04:02 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 18:42:34 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	ft_circular_lstclear(t_stack **lst)
{
	t_stack		*cursor;
	t_stack		*previous;

	cursor = *lst;
	previous = cursor;
	cursor = cursor->next;
	free(previous);
	while (cursor != *lst)
	{
		previous = cursor;
		cursor = cursor->next;
		free(previous);
	}
	previous = 0;
	*lst = 0;
}

static void	free_manager(t_var *var, int gnl_free)
{
	if (gnl_free == GNL_FREE)
		ft_free_gnl_stdin();
	ft_if_free((void **)&var->args.ptr);
	ft_if_free((void **)&var->args.index);
	ft_if_free((void **)&var->lis.ptr);
	if (var->stack_a)
	{
		ft_circular_lstclear(&var->stack_a);
		var->stack_a = 0;
	}
	if (var->stack_b)
	{
		ft_circular_lstclear(&var->stack_b);
		var->stack_b = 0;
	}
}

void		exit_manager(t_var *var, int errnum, int gnl_free)
{
	free_manager(var, gnl_free);
	if (errnum == OK)
		ft_printf("OK\n");
	if (errnum == KO)
		ft_printf("KO\n");
	if (errnum == ERROR)
		ft_printf("Error\n");
	if (errnum == MALLOC)
		ft_printf("Memory allocation failed\n");
	exit(1);
}
