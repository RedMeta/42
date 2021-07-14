/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:04:42 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 15:21:22 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Structures
*/

typedef	struct		s_args
{
	int				*ptr;
	int				*index;
	int				len;
	int				max;
	int				min;
}					t_args;

typedef struct		s_lis
{
	int				*ptr;
	int				length;
}					t_lis;

typedef struct		s_info
{
	int				len;
	int				max;
	int				min;
	int				pos_max;
	int				pos_min;
}					t_info;

typedef struct		s_stack
{
	int				n;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_moves
{
	int				pos_in_a;
	int				pos_in_b;
	int				moves;
	int				directions;
}					t_moves;

typedef struct		s_count
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_count;

typedef struct		s_flags
{
	int				gui;
	int				verbose;
	int				counts;
}					t_flags;

typedef struct		s_var
{
	t_args			args;
	t_lis			lis;
	t_info			info_a;
	t_info			info_b;
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_moves			moves;
	t_count			count;
	t_flags			flags;
}					t_var;

typedef struct		s_info_moves
{
	t_moves			moves;
	t_moves			same;
	t_moves			diff;
	int				moves_same_str;
	int				moves_same_rev;
	int				moves_diff_str;
	int				moves_diff_rev;
}					t_info_moves;

typedef struct		s_gui
{
	t_stack			*cursor_a;
	t_stack			*cursor_b;
	int				tab;
}					t_gui;

#endif
