/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:54:20 by erandal           #+#    #+#             */
/*   Updated: 2019/09/18 01:07:19 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		j;
	int		n;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	j = ft_strlen((char *)s) - 1;
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	if (j < i)
		j = i;
	tmp = (char *)malloc((j - i + 2));
	if (!(tmp))
		return (NULL);
	n = 0;
	while (i <= j)
		tmp[n++] = s[i++];
	tmp[n] = '\0';
	return (tmp);
}
