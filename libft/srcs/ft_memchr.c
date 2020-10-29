/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:10:47 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 13:49:42 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sl;

	i = 0;
	sl = (unsigned char*)s;
	while (++i <= n)
		if (*(sl++) == (unsigned char)c)
			return ((void*)--sl);
	return (0);
}
