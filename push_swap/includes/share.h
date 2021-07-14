/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   share.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:39:41 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 15:00:18 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

/*
** Includes
*/

# include "struct.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>

/*
** Defines
*/

# define A 0
# define B 1
# define PRINT 1
# define NOT_PRINT 0
# define YES 1
# define NO 0
# define NT -1
# define OK 0
# define KO 1
# define ERROR 2
# define MALLOC 3
# define GNL_FREE 1
# define NOT_GNL_FREE 0

/*
** Prototypes
*/

/*
** Initialize
*/

void				initialize(t_var *var);
void				take_numbers(t_var *var, int argc, char **argv);
void				index_stack(t_var *var);
int					find_index(t_var *var, int n);

/*
** Info
*/

void				ft_find_stack_a_limits(t_var *var);

/*
** Operations
*/

void				operation_swap(t_var *var, int a_or_b,
					int print, int from_double);
void				operation_double_swap(t_var *var, int print);
void				operation_rotate(t_var *var, int a_or_b,
					int print, int from_double);
void				operation_double_rotate(t_var *var, int print);
void				operation_rev_rotate(t_var *var, int a_or_b,
					int print, int from_double);
void				operation_double_rev_rotate(t_var *var, int print);
void				operation_push_to_a(t_var *var, int print);
void				operation_push_to_b(t_var *var, int print);

/*
** Print
*/

void				print_counts(t_var *var);
void				print_stacks(t_var *var);
void				print_fake_gui(t_var *var);

/*
** Free
*/

void				if_free(void **freeable);

/*
** Exit
*/

void				exit_manager(t_var *var, int errnum, int gnl_free);

#endif
