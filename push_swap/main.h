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
	char			stack;
	struct s_list	*next;
};

typedef struct s_list list;

/*
** DLL function prototypes
*/

list	*get_first_elem_dll(list *item);
list	*get_last_elem_dll(list *item);
list	*new_item_dll(int n, char b);
int	add_first_dll(list *head, list *item);
int	add_last_dll(list *head, list *item);

/*
** MOVES function prototypes
*/

int	swap_top(list *item);
int	first_to_last(list *item);
int	last_to_first(list *item);
int	first_elem_push(list *item1, list *item2);


/*
** SUPPORT function prototypes
*/

int	print_all_dll(list *item);
#endif

