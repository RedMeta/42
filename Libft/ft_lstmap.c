/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:14:34 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/17 14:14:37 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_cursor;
	t_list	*cursor;

	new_lst = ft_lstnew(f(lst->content));
	if (!lst || !new_lst || !*f)
		return (NULL);
	new_cursor = new_lst;
	cursor = lst->next;
	while (cursor)
	{
		new_cursor->next = ft_lstnew(f(cursor->content));
		if (!new_cursor)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_cursor = new_cursor->next;
		cursor = cursor->next;
	}
	return (new_lst);
}
