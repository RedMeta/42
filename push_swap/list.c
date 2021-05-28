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

list	*new_item(unsigned n)
{
	list *item;

	item = (list *)(malloc(sizeof(list)));
	if (!item)
		return(NULL);
	item->num = n;
	item->prev = NULL;
	item->next = NULL;
	return (item);
}

int	add_first(list *head, list *item)
{
	if (!item || !head)
		return(-1);
	while (head->prev)
		head = head->prev;
	head->prev = item;
	item->next = head;
	return(0);
}
