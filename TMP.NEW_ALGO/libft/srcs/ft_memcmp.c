/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:16:01 by erandal           #+#    #+#             */
/*   Updated: 2019/09/15 20:37:55 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sl1;
	unsigned char	*sl2;

	i = 0;
	if (n == 0)
		return (0);
	sl1 = (unsigned char *)s1;
	sl2 = (unsigned char *)s2;
	while ((*sl1 == *sl2) && (++i < n))
	{
		sl1++;
		sl2++;
	}
	return ((int)(*sl1 - *sl2));
}
