/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinamet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:50:47 by asinamet          #+#    #+#             */
/*   Updated: 2021/01/16 15:00:29 by asinamet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conta_parole(char const *s, char c)
{
	int	i;
	int	parole;

	i = 0;
	parole = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			parole++;
		i++;
	}
	return (parole);
}

static int	lung_parola(char const *s, char c)
{
	int i;
	int lung;

	i = 0;
	lung = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		lung++;
	}
	return (lung);
}

static void	*libera(char **splittato, int parola)
{
	int i;

	i = 0;
	while (i < parola)
	{
		free(splittato[i]);
		i++;
	}
	free(splittato);
	return (NULL);
}

static char	**riempi(char const *s, int parole, char c, char **splittato)
{
	int	i;
	int	j;
	int	lung;

	i = -1;
	while (++i < parole)
	{
		while (*s == c)
			s++;
		lung = lung_parola(s, c);
		if (!(splittato[i] = (char *)malloc(sizeof(char) * (lung + 1))))
			return (libera(splittato, i));
		j = 0;
		while (j < lung)
			splittato[i][j++] = *s++;
		splittato[i][j] = '\0';
	}
	splittato[i] = NULL;
	return (splittato);
}

char		**ft_split(char const *s, char c)
{
	char	**splittato;
	int		num_parole;

	if (!s)
		return (NULL);
	num_parole = conta_parole(s, c);
	if (!(splittato = (char **)malloc(sizeof(char*) * (num_parole + 1))))
		return (NULL);
	splittato = riempi(s, num_parole, c, splittato);
	return (splittato);
}
