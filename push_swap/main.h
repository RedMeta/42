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
** Struct declaration and typedef for the double linked list and the bucket
*/

struct s_list
{
	struct s_list	*prev;
	unsigned		num;
	struct s_list	*next;
};

typedef struct s_list list;

struct s_bucket
{
	struct s_list	*first_el;
	struct s_list	*last_el;
	char			id;
	struct s_bucket	*next;
};

typedef struct s_bucket	bucket;

/*
** DLL function prototypes
*/

list	*get_first_elem_dll(list *item);
list	*get_last_elem_dll(list *item);
list	*new_item_dll(int n);
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

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int	init(int *argc, char **argv[]);
int	print_all_dll(list *item);

/*
** BUCKET function prototypes
*/

#endif

