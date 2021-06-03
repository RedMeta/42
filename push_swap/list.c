/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:58:18 by asinamet          #+#    #+#             */
/*   Updated: 2021/05/24 11:58:20 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

list	*get_first_elem_dll(list *item)
{
	if (!item)
		return (NULL);
	while (item->prev)
		item = item->prev;
	return (item);
}

list	*get_last_elem_dll(list *item)
{
	if (!item)
		return (NULL);
	while (item->next)
		item = item->next;
	return (item);
}

list	*new_item_dll(int n, char b)
{
	list *item;

	item = (list *)(malloc(sizeof(list)));
	if (!item)
		return(NULL);
	item->num = n;
	item->prev = NULL;
	item->next = NULL;
	item->stack = b;
	return (item);
}

int	add_first_dll(list *head, list *item)
{
	if (!item || !head)
		return(-1);
	head = get_first_elem_dll(head);
	head->prev = item;
	item->next = head;
	return(1);
}

int	add_last_dll(list *head, list *item)
{
	if (!item || !head)
		return (-1);
	head = get_last_elem_dll(head);
	head->next = item;
	item->prev = head;
	return (1);
}

int	print_all_dll(list *item)
{
	int i;

	i = -1;
	if (!item)
		return (-1);
	while (item->prev)
	item = get_first_elem_dll(item);
	while (item->next)
	{
		printf("Element n.%d has value #%d#\n", ++i, item->num);
		item = item->next;
	}
	printf("Element n.%d has value #%d#\n", ++i, item->num);
	return (i + 1);
}

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
	return(0);
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

