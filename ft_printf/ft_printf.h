/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 13:42:30 by asinamet          #+#    #+#             */
/*   Updated: 2021/02/25 13:42:32 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr_base(int n, char *base);
int		ft_printf(const char *input, ...);

#endif
