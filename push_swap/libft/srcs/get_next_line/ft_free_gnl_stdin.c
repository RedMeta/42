/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_gnl_stdin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <asinamet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:13:09 by asinamet          #+#    #+#             */
/*   Updated: 2021/06/26 16:13:19 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_gnl_stdin(void)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) >= 0)
	{
		if (line)
			free(line);
		if (!ret)
			break ;
	}
}
