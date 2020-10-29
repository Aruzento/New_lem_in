/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:48:49 by erandal           #+#    #+#             */
/*   Updated: 2019/10/08 04:42:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss1;
	char	*ss2;
	char	*s;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (!(s = (char *)malloc(ft_strlen(ss1) + ft_strlen(ss2) + 1)))
		return (NULL);
	k = 0;
	while (*(ss1))
		s[k++] = *ss1++;
	while (*(ss2))
		s[k++] = *ss2++;
	s[k] = '\0';
	return (s);
}
