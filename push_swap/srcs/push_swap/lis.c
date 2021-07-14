/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 18:24:35 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 18:42:19 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

static void	save_lis(t_var *var, int *index)
{
	int i;
	int	tmp;

	i = var->info_a.len - 1;
	tmp = var->lis.length;
	while (i >= 0)
	{
		if (index[i] == tmp)
		{
			var->lis.ptr[tmp] = var->args.ptr[i];
			--tmp;
		}
		--i;
	}
}

static void	search_lis(t_var *var, int *tmp_lis, int *index)
{
	int i;

	i = 0;
	while (i < var->info_a.len)
	{
		index[i] = search_replace(tmp_lis, 0, i, var->args.ptr[i]);
		if (var->lis.length < index[i])
			var->lis.length = index[i];
		i++;
	}
}

static void	initialize_lis(t_var *var, int *tmp_lis, int *index)
{
	int i;

	i = 1;
	tmp_lis[0] = var->args.ptr[0];
	while (i < var->info_a.len)
	{
		tmp_lis[i] = 2147483647;
		index[i] = 0;
		i++;
	}
}

void		find_lis(t_var *var)
{
	int	*index;
	int	*tmp_lis;

	if (!(index = (int *)malloc(var->info_a.len * sizeof(int))))
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	if (!(tmp_lis = (int *)malloc(var->info_a.len * sizeof(int))))
	{
		free(index);
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	}
	initialize_lis(var, tmp_lis, index);
	search_lis(var, tmp_lis, index);
	if (!(var->lis.ptr = (int *)malloc((var->lis.length + 1) * sizeof(int))))
	{
		free(index);
		free(tmp_lis);
		exit_manager(var, MALLOC, NOT_GNL_FREE);
	}
	save_lis(var, index);
	free(index);
	free(tmp_lis);
	clean_stack_a(var);
}
