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
	list *bucket1;
	bucket1 = new_item(0);
	while (n++ < 10)
		add_first(bucket1, new_item(n));
	while (bucket1->prev)
		bucket1 = bucket1->prev;
	while (bucket1->next)
	{
		printf("---%d---\n", bucket1->num);
		bucket1 = bucket1->next;
	}
	printf("---%d---\n", bucket1->num);
    return 0;
}