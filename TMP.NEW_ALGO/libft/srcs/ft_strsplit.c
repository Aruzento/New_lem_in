/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:12:39 by erandal           #+#    #+#             */
/*   Updated: 2019/09/20 13:54:50 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	letters(char *str, int i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	words(char *str, char c)
{
	int i;
	int w;

	w = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static char	**globalfree(char **tmp, int w)
{
	if (w > 0)
		free(tmp[0]);
	while (w)
		free(tmp[w--]);
	free(tmp);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tmp;
	char	*str;
	int		i;
	int		j;
	int		w;

	if (!s || !(str = (char *)s))
		return (NULL);
	if (!(tmp = (char**)ft_memalloc(sizeof(char **) * words(str, c) + 1)))
		return (NULL);
	i = -1;
	w = 0;
	while (str[++i])
		if (str[i] != c)
		{
			j = letters(str, i, c);
			if (!(tmp[w] = ft_strsub(str, i, j - i)))
				return (globalfree(tmp, w));
			w++;
			i = j - 1;
		}
	tmp[w] = NULL;
	return (tmp);
}
