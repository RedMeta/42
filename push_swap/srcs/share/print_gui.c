/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:29:20 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/29 16:05:16 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

static void	print_not_line(int stack, int tab)
{
	if (stack == A)
		ft_printf("%*.d | ", tab, 0);
	else
		ft_printf("\n", 0);
}

static void	print_line_b(t_var *var, t_gui *gui, int n)
{
	int spaces;
	int	tmp;

	spaces = find_index(var, n);
	tmp = spaces;
	while (spaces)
	{
		ft_printf("\e[48;2;83;15;107m \e[0m");
		spaces--;
	}
	while (var->args.len - tmp >= 0)
	{
		ft_printf(" ");
		tmp++;
	}
	ft_printf("\n");
	gui->cursor_b = gui->cursor_b->next;
}

static void	print_line_a(t_var *var, t_gui *gui, long n)
{
	int	spaces;
	int	tmp;

	spaces = find_index(var, n);
	tmp = spaces;
	while (spaces)
	{
		ft_printf("\e[48;2;141;26;184m \e[0m");
		spaces--;
	}
	while (var->args.len - tmp >= 0)
	{
		ft_printf(" ");
		tmp++;
	}
	ft_printf(" | ");
	gui->cursor_a = gui->cursor_a->next;
}

static void	init_fake_gui(t_var *var, t_gui *gui)
{
	usleep(50000 * (var->args.len % 50));
	system("clear");
	gui->tab = var->args.len + 1;
	ft_printf("\e[38;2;141;26;184m%*s \e[0m| \e[38;2;83;15;107m%*s\e[0m\n",
	gui->tab, "Stack A", -gui->tab, "Stack B");
}

void		print_fake_gui(t_var *var)
{
	t_gui	gui;

	init_fake_gui(var, &gui);
	gui.cursor_a = var->stack_a;
	gui.cursor_b = var->stack_b;
	if (gui.cursor_a)
		print_line_a(var, &gui, gui.cursor_a->n);
	else
		print_not_line(A, gui.tab);
	if (gui.cursor_b)
		print_line_b(var, &gui, gui.cursor_b->n);
	else
		print_not_line(B, gui.tab);
	while (gui.cursor_a != var->stack_a || gui.cursor_b != var->stack_b)
	{
		if (gui.cursor_a && gui.cursor_a != var->stack_a)
			print_line_a(var, &gui, gui.cursor_a->n);
		else
			print_not_line(A, gui.tab);
		if (gui.cursor_b && gui.cursor_b != var->stack_b)
			print_line_b(var, &gui, gui.cursor_b->n);
		else
			print_not_line(B, gui.tab);
	}
}
