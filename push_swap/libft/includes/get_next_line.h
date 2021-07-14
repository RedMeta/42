/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:32:21 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/25 17:26:49 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** Includes
*/

# include <unistd.h>
# include <stdlib.h>

/*
** Defines
*/

# define BUFFER_SIZE 42

/*
** Structures
*/

typedef struct		s_file
{
	int				fd;
	char			buffer[BUFFER_SIZE + 1];
	struct s_file	*next;
}					t_file;

typedef struct		s_index
{
	size_t			i;
	size_t			j;
}					t_index;

/*
** Prototypes
*/

int					ft_lstclear(t_file **head);
int					ft_list_remove_if(t_file **head, int fd);
void				ft_buffzero(char *buffer, int start);
char				*ft_reallocpy(char *buffer, char *line);
t_file				*ft_lst_find_or_create(t_file **head, int fd);

#endif
