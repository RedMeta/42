/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:32:11 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/14 15:37:38 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(char *buffer, char **line)
{
	t_index	index;
	char	*new_line;

	if (!(new_line = ft_reallocpy(buffer, *line)))
		return (-1);
	if (*line)
		free(*line);
	*line = new_line;
	index.i = 0;
	while (buffer[index.i] && buffer[index.i] != '\n')
		buffer[index.i++] = 0;
	if (!buffer[index.i])
		return (0);
	if (buffer[index.i] == '\n')
	{
		buffer[index.i++] = 0;
		index.j = 0;
		while (buffer[index.i + index.j])
		{
			buffer[index.j] = buffer[index.i + index.j];
			index.j++;
		}
		ft_buffzero(buffer, index.j);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_file	*head;
	t_file			*actual;
	ssize_t			reader;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line ||
	!(actual = ft_lst_find_or_create(&head, fd)))
		return (-1);
	if (!head)
		head = actual;
	*line = NULL;
	if ((reader = read_buffer(actual->buffer, line)))
		return (reader == -1 ? ft_lstclear(&head) : reader);
	while (((reader = read(fd, actual->buffer, BUFFER_SIZE)) > 0))
		if ((reader = read_buffer(actual->buffer, line)))
			return (reader == -1 ? ft_lstclear(&head) : reader);
	if (!reader)
		return (ft_list_remove_if(&head, fd));
	ft_lstclear(&head);
	return (-1);
}
