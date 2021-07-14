/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:32:29 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/10 10:45:24 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				ft_buffzero(char *buffer, int start)
{
	while (start <= BUFFER_SIZE)
		buffer[start++] = 0;
}

t_file				*ft_lst_find_or_create(t_file **head, int fd)
{
	t_file	*cursor;
	t_file	*last;

	cursor = *head;
	while (cursor)
	{
		if (cursor->fd == fd)
			return (cursor);
		if (!cursor->next)
			break ;
		cursor = cursor->next;
	}
	if (!(cursor = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	if (*head)
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = cursor;
	}
	cursor->fd = fd;
	ft_buffzero(cursor->buffer, 0);
	cursor->next = NULL;
	return (cursor);
}

int					ft_list_remove_if(t_file **head, int fd)
{
	t_file	*actual;
	t_file	*next;
	t_file	*previous;

	actual = *head;
	while (actual)
	{
		next = actual->next;
		if (actual->fd == fd)
		{
			if (actual == *head)
				*head = next;
			else
				previous->next = next;
			free(actual);
			actual = NULL;
		}
		else
			previous = actual;
		actual = next;
	}
	return (0);
}

int					ft_lstclear(t_file **head)
{
	t_file	**free_head;
	t_file	*previous;

	free_head = head;
	while (*head)
	{
		previous = *head;
		*head = (*head)->next;
		free(previous);
	}
	free(free_head);
	return (-1);
}

char				*ft_reallocpy(char *buffer, char *line)
{
	t_index	index;
	char	*new_line;

	index.i = 0;
	index.j = 0;
	while (buffer[index.i] && buffer[index.i] != '\n')
		index.i++;
	while (line && line[index.j])
		index.j++;
	if (!(new_line = (char *)malloc((index.i + index.j + 1) * sizeof(char))))
		return (NULL);
	index.i = 0;
	index.j = 0;
	while (line && line[index.j])
	{
		new_line[index.j] = line[index.j];
		line[index.j++] = 0;
	}
	while (buffer[index.i] && buffer[index.i] != '\n')
	{
		new_line[index.j + index.i] = buffer[index.i];
		index.i++;
	}
	new_line[index.j + index.i] = 0;
	return (new_line);
}
