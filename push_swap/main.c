/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:58:18 by asinamet          #+#    #+#             */
/*   Updated: 2021/05/24 11:58:20 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

int main()
{
	int	n = 0;
	list *stack1;
	list *stack2;

	stack1 = new_item_dll(0, 'a');
	stack2 = new_item_dll(1, 'b');
	while (n++ < 3)
	{
		add_last_dll(stack1, new_item_dll(n * 3, 'a'));
		add_last_dll(stack2, new_item_dll(n * -3, 'b'));
	}

	n = print_all_dll(stack1);
	printf("There are %d elements in stack '%c' ;\n", n, stack1->stack);
	n = print_all_dll(stack2);
	printf("There are %d elements in stack '%c' ;\n", n, stack2->stack);
	stack1 = get_last_elem_dll(stack1);
	first_elem_push(stack1, stack2);
	printf("New stacks\n");
	n = print_all_dll(stack1);
	printf("There are %d elements in stack '%c' ;\n", n, stack1->stack);
	n = print_all_dll(stack2);
	printf("There are %d elements in stack '%c' ;\n", n, stack2->stack);
    return 0;
}