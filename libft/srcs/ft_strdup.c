/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:36:26 by erandal           #+#    #+#             */
/*   Updated: 2020/09/15 02:09:07 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(src))
		return (NULL);
	while (src[i])
		i++;
	tmp = (char *)malloc(i + 1);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		tmp[i] = src[i];
	tmp[i] = '\0';
	return (tmp);
}
