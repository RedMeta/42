/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:59:01 by asinamet          #+#    #+#             */
/*   Updated: 2021/05/24 11:59:04 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** Struct declaration for the double linked list and typedef
*/

struct s_list
{
	struct s_list	*prev;
	unsigned		num;
	struct s_list	*next;
};

typedef struct s_list list;

/*
** Function prototypes
*/

list	*new_item(unsigned n);
int		add_first(list *head, list *item);


#endif

