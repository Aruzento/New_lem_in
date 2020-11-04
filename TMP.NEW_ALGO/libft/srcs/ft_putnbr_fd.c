/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:29:42 by erandal           #+#    #+#             */
/*   Updated: 2019/09/18 03:23:06 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nn;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nn = (unsigned int)(n * -1);
	}
	else
		nn = (unsigned int)n;
	if (nn >= 10)
		ft_putnbr_fd(nn / 10, fd);
	ft_putchar_fd(nn % 10 + 48, fd);
}
