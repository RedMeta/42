/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:23:07 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 14:23:09 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_init(int (**func)(t_flags *, va_list *))
{
	func[0] = &put_perc;
	func[1] = &put_c;
	func[2] = &put_s;
	func[3] = &put_i;			
	func[4] = &put_i;
	func[5] = &put_i;
	func[7] = &put_x;
	func[8] = &put_X;
/*	func[3] = &put_p; 				WORK IN PROGRESS */
}

int		put_select(t_flags *flags, va_list *args)
{
	int res;
	int	(*put_func[10])(t_flags *, va_list *);

	put_init(put_func);
	res = put_func[flags->conv](flags, args);
	return res;
}

int		ft_chrFnd(const char *str, char c)
{
	int i;
	i = 0;
	while ((str[i] != c) && str[i])
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}
