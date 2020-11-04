/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:17:41 by erandal           #+#    #+#             */
/*   Updated: 2019/09/18 03:25:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n / 10 > 0)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

static void	ft_trstr(unsigned int n, char *tmp, int i, int f)
{
	if (n / 10 != 0)
		ft_trstr(n / 10, tmp, i - 1, f);
	if (f)
		tmp[0] = '-';
	tmp[i] = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	char			*tmp;
	int				f;
	unsigned int	un;

	f = 0;
	if (n < 0)
	{
		un = (unsigned int)(n * -1);
		f = 1;
	}
	else
		un = (unsigned int)n;
	if (!(tmp = ft_memalloc(f + ft_digits(un) + 1)))
		return (NULL);
	ft_trstr(un, tmp, ft_digits(un) + f - 1, f);
	tmp[ft_digits(un) + f] = '\0';
	return (tmp);
}
