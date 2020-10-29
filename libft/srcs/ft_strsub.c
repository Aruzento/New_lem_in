/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:31:07 by erandal           #+#    #+#             */
/*   Updated: 2020/08/12 18:57:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ss;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (start > i)
		return (NULL);
	if (!(ss = ft_strnew(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
		ss[i++] = s[start++];
	ss[i] = '\0';
	return (ss);
}
