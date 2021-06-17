/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:10:22 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/03 12:10:24 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

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

list	*new_item_dll(int n)
{
	list	*item;

	item = (list *)(malloc(sizeof(list)));
	if (!item)
		return (NULL);
	item->num = n;
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

int	add_first_dll(list *head, list *item)
{
	if (!item || !head)
		return (-1);
	head = get_first_elem_dll(head);
	head->prev = item;
	item->next = head;
	return (1);
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
