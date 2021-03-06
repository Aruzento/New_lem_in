/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 03:53:42 by erandal           #+#    #+#             */
/*   Updated: 2020/11/05 14:00:02 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ln_print(int tp, int ant, char *name)
{
	if (tp == 1)
	{
		ft_putstr("\033[34m|");
		ft_putnbr(ant);
		ft_putstr("|: \033[0m");
	}
	else
	{
		ft_putchar('L');
		ft_putnbr(ant);
		ft_putstr("->");
		ft_putstr(name);
		ft_putchar(' ');
	}
}

void	line_tap(t_lemon *root, int *f, int *i, int j)
{
	t_ways	*w;
	int		k;

	k = 0;
	w = root->all_ways[root->best_ways[j]]->first->last;
	while (++k < root->all_ways[root->best_ways[j]]->way_l - 1)
	{
		w->ant = w->prev->ant;
		if (w->ant)
			ln_print(0, w->ant, w->s_way->name);
		(*f) += w->ant;
		w = w->prev;
	}
	if ((*i) <= root->ants)
	{
		w->ant = (*i);
		(*f) += w->ant;
		ln_print(0, w->ant, w->s_way->name);
		(*i)++;
	}
	else
		w->ant = 0;
}

void	best_nun_check(t_lemon *root)
{
	ft_putstr("\n");
	if (root->num_best == 0)
	{
		write(1, "No any way from START to END\n", 30);
		return ;
	}
}

void	get_result(t_lemon *root)
{
	int		f;
	int		i;
	int		j;

	f = 1;
	i = 1;
	best_nun_check(root);
	while (i <= root->ants || f)
	{
		j = -1;
		f = 0;
		if (root->iter_num)
			ln_print(1, root->iter_num++, "iter");
		while (++j < root->num_best)
			line_tap(root, &f, &i, j);
		if (i <= root->ants || f)
			ft_putstr("\n");
	}
}
