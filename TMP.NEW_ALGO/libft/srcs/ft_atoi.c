/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:54:27 by erandal           #+#    #+#             */
/*   Updated: 2020/07/25 14:55:46 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	err_atoi(void)
{
	write(7, "Error\n\0", 1);
	exit(1);
}

int		ft_atoi(const char *str)
{
	int			i;
	int			check;
	int			v;
	int			neg;

	neg = 0;
	i = 0;
	check = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		neg = (*(str++) == '-') ? 1 : 0;
	check = *str - '0';
	while (*str && (*str >= '0') && (*str <= '9'))
		v = v * 10 + (*(str++) - 48);
	if ((v == 0) && (check != v))
		err_atoi();
	return ((neg) ? v * -1 : v);
}
