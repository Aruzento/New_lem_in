/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:29:15 by erandal           #+#    #+#             */
/*   Updated: 2019/09/15 15:19:34 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	int		i;
	int		j;
	size_t	ti;

	i = -1;
	while (hay[++i])
	{
		ti = i;
		j = 0;
		while ((hay[ti] == nee[j]) && (nee[j]) && (ti < len))
		{
			ti++;
			j++;
		}
		if (!(nee[j]))
		{
			while (i-- != 0)
				hay++;
			return ((char *)hay);
		}
	}
	return (NULL);
}
