/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:49:36 by erandal           #+#    #+#             */
/*   Updated: 2019/09/18 03:23:26 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nn;

	if (n < 0)
	{
		ft_putchar('-');
		nn = (unsigned int)(n * -1);
	}
	else
		nn = (unsigned int)n;
	if (nn >= 10)
		ft_putnbr(nn / 10);
	ft_putchar(nn % 10 + 48);
}
