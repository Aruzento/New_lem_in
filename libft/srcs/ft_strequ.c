/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:23:34 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 15:00:26 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char *ss1;
	char *ss2;

	if (!(s1) || !(s2))
		return (0);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while (*ss1 || *ss2)
	{
		if (*ss1 != *ss2)
			return (0);
		ss1++;
		ss2++;
	}
	return (1);
}
