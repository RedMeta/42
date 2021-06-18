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
** Struct declaration and typedef for the double linked list and the stack
*/

struct s_list
{
	struct s_list	*prev;
	unsigned		num;
	struct s_list	*next;
};

typedef struct s_list list;

struct s_stack
{
	struct s_list	*first_el;
	struct s_list	*last_el;
	char			id;
	struct s_stack	*next;
};

typedef struct s_stack	stack;

/*
** DLL function prototypes
*/

list	*get_first_elem_dll(list *item);
list	*get_last_elem_dll(list *item);
list	*new_item_dll(int n);
int	add_first_dll(list *head, list *item);
int	add_last_dll(list *head, list *item);

int	swap_top(list *item);
int	first_to_last(list *item);
int	last_to_first(list *item);
int	first_elem_push(list *item1, list *item2);

/*
** MOMENT function prototypes
*/

int	init(int argc, char **argv);
int	list_check(char **list, int x, int max);
int	input_check(int *input, int size);
int	list_to_arr(char **inp, int count, int **res);


/*
** SUPPORT function prototypes
*/

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int	print_all_dll(list *item);


/*
** MINILIBFT function prototypes
*/

char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
int	ft_isspace(int c);

#endif

