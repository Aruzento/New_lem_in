/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_print_alt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:16:19 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 15:21:24 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	alt_print(t_lemon *root)
{
	t_ways	*w;
	int		i;
	int		j;

	i = -1;
	ft_putendl("Rooms:\n");
	while (++i < root->num_best)
	{
		j = -1;
		ft_putchar('|');
		ft_putnbr(i);
		ft_putstr("|: ");
		w = root->all_ways[i]->first;
		while (++j < w->first->way_l - 1)
		{
			ft_putstr(w->s_way->name);
			ft_putstr(" -> ");
			w = w->next;
		}
		ft_putendl(w->s_way->name);
	}
}