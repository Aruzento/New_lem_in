/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:33:04 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 13:52:28 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *h, char *n, int i, int j)
{
	while ((h[i] == n[j]) && (n[j]))
	{
		i++;
		j++;
	}
	if ((h[i] != n[j]) && (n[j] != '\0'))
		return (0);
	return (1);
}

char		*ft_strstr(const char *hay, const char *nee)
{
	int		i;
	int		j;
	char	*hy;
	char	*ne;

	if (!(*nee))
		return ((char *)hay);
	hy = (char *)hay;
	ne = (char *)nee;
	i = -1;
	j = 0;
	while (hy[++i])
		if (check(hy, ne, i, j))
		{
			while (i-- != 0)
				hy++;
			return (hy);
		}
	return (NULL);
}
