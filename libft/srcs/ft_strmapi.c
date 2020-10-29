/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:12:03 by erandal           #+#    #+#             */
/*   Updated: 2019/09/17 14:56:54 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*cln;
	int		i;

	if (!s || !(cln = ft_memalloc((size_t)ft_strlen((char*)s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		cln[i] = (*f)(i, s[i]);
	cln[i] = '\0';
	return (cln);
}
