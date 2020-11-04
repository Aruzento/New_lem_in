/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:08:43 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 15:01:23 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *ss1;
	char *ss2;

	if (!(s1) || !(s2))
		return (0);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while ((*ss1 || *ss2) && n--)
		if (*ss1++ != *ss2++)
			return (0);
	return (1);
}
