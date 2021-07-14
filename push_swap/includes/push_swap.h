/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:39:44 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/27 15:16:11 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** Includes
*/

# include "share.h"

/*
** Prototypes
*/

/*
** Sorting
*/

int		sort_less_five(t_var *var);
int		sort(t_var *var);
void	find_lis(t_var *var);
void	clean_stack_a(t_var *var);
t_moves	find_min_moves(t_var *var, int n, int pos_in_b);

/*
** Loops
*/

void	loop_same_str(t_var *var);
void	loop_same_rev(t_var *var);
void	loop_diff_str(t_var *var);
void	loop_diff_rev(t_var *var);

#endif
