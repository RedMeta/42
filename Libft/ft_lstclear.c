/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:14:34 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/17 14:14:37 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_elem;
	t_list	*next_elem;

	next_elem = *lst;
	while (next_elem)
	{
		current_elem = next_elem;
		next_elem = current_elem->next;
		ft_lstdelone(current_elem, del);
	}
	*lst = NULL;
}
