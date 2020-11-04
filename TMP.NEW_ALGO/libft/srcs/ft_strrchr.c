/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:20:22 by erandal           #+#    #+#             */
/*   Updated: 2019/09/15 20:57:51 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ss;

	ss = NULL;
	while (*s)
	{
		if (*s == c)
			ss = (char *)s;
		s++;
	}
	if (ss)
		return (ss);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
