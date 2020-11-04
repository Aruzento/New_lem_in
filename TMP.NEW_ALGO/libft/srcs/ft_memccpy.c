/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:04:05 by erandal           #+#    #+#             */
/*   Updated: 2019/09/15 20:11:03 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sr;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	if (dest == src)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		dst[i] = sr[i];
		if (dst[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
	}
	return (NULL);
}
