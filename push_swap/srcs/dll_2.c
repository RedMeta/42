/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:10:22 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/03 12:10:24 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	swap_top(list *item)
{
	int	m;

	if (!item)
		return (-1);
	item = get_first_elem_dll(item);
	if (item->next)
	{
		m = item->next->num;
		item->next->num = item->num;
		item->num = m;
		return (1);
	}
	return (0);
}

int	first_to_last(list *item)
{
	list	*first;
	list	*last;

	if (!item)
		return (-1);
	first = get_first_elem_dll(item);
	last = get_last_elem_dll(item);
	if (first != last)
	{
		first->next->prev = NULL;
		first->next = NULL;
		first->prev = last;
		last->next = first;
		return (1);
	}
	return (0);
}

int	last_to_first(list *item)
{
	list	*first;
	list	*last;

	if (!item)
		return (-1);
	first = get_first_elem_dll(item);
	last = get_last_elem_dll(item);
	if (first != last)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		return (1);
	}
	return (0);
}

int	first_elem_push(list *item1, list *item2)
{
	list	*head1;
	list	*head2;

	if (!item1 || !item2)
		return (-1);
	head1 = get_first_elem_dll(item1);
	head2 = get_first_elem_dll(item2);
	if (head1 != head2)
	{
		head1->next->prev = NULL;
		head1->next = head2;
		head2->prev = head1;
		return (1);
	}
	return (0);
}
