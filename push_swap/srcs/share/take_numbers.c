/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:07:52 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 17:49:38 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void		save_number(t_var *var, int n)
{
	t_stack		*cursor;
	t_stack		*last;

	last = 0;
	cursor = var->stack_a;
	while (cursor)
	{
		if (cursor->n == n)
			exit_manager(var, ERROR, NOT_GNL_FREE);
		if (cursor->next == var->stack_a && (last = cursor))
			break ;
		cursor = cursor->next;
	}
	if (!(cursor = (t_stack *)malloc(sizeof(t_stack))))
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	if (!var->stack_a)
		var->stack_a = cursor;
	cursor->n = n;
	cursor->previous = last;
	cursor->next = var->stack_a;
	if (last)
		last->next = cursor;
	(var->stack_a)->previous = cursor;
}

static void		check_if_valid(t_var *var, char *n)
{
	if (!ft_isdigit_string(n) || ft_atol(n) > 2147483647 ||
	ft_atol(n) < -2147483648)
		exit_manager(var, ERROR, NOT_GNL_FREE);
}

static int		*append_to_tab(t_var *var, char *s)
{
	char	**tmp;
	int		*new;
	int		tmp_len;
	int		i;

	if (!(tmp = ft_split(s, " ")))
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	tmp_len = ft_mtxlen(tmp);
	if (!(new = (int *)malloc((var->info_a.len + tmp_len) * sizeof(int))))
	{
		ft_free_mtx(tmp);
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	}
	ft_tabcpy(new, var->args.ptr, var->info_a.len);
	ft_if_free((void **)&var->args.ptr);
	i = 0;
	while (tmp[i])
	{
		check_if_valid(var, tmp[i]);
		new[i + var->info_a.len] = ft_atoi(tmp[i]);
		i++;
	}
	ft_free_mtx(tmp);
	var->info_a.len += tmp_len;
	return (new);
}

void			take_numbers(t_var *var, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		exit(1);
	i = 1;
	while (i < argc)
	{
		var->args.ptr = append_to_tab(var, argv[i]);
		i++;
	}
	i = 0;
	while (i < var->info_a.len)
	{
		if (var->args.ptr[i] < var->args.min)
			var->args.min = var->args.ptr[i];
		if (var->args.ptr[i] > var->args.max)
			var->args.max = var->args.ptr[i];
		save_number(var, var->args.ptr[i]);
		i++;
	}
	var->args.len = var->info_a.len;
}
