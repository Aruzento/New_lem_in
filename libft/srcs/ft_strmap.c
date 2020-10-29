/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:40:54 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 14:55:26 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cln;
	int		i;

	if (!s || !(cln = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		cln[i] = (*f)(s[i]);
	cln[i] = '\0';
	return (cln);
}
