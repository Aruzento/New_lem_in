/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:09:36 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 20:31:58 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ln_print(int tp, int ant, char *name)
{
	if (tp == 1)
	{
		ft_putstr("|");
		ft_putnbr(ant);
		ft_putstr("|: ");
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

void	get_some_best(t_lemon *root, int f)
{
	int		j;
	int		i;
	t_ways	*w;

	while (f)
	{
		j = -1;
		i = 0;
		f = 0;
		while (++j < root->num_best)
		{
			w = root->all_ways[root->best_ways[j]]->first;
			i += w->way_l;
		}
		j = -1;
		while (++j < root->num_best)
		{
			w = root->all_ways[root->best_ways[j]]->first;
			if (((root->ants / root->num_best)
				+ ((i / root->num_best) - 2)) < w->way_l)
				f++;
		}
		root->num_best -= f;
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

int		best_nun_check(t_lemon *root)
{
	if (root->num_best == 0)
		err_exit(root, "\033[31;1mError: None possible solution!\033[0m");
	get_some_best(root, 1);
	if (root->num_best == 0)
		root->num_best = 1;
	return (1);
}

void	get_result(t_lemon *root)
{
	int		f;
	int		i;
	int		j;

	if (!best_nun_check(root))
		return ;
	i = -1;
	while (++i < root->line_num)
		ft_putendl(root->input_lines[i]);
	ft_putchar('\n');
	f = 1;
	i = 1;
	while (i <= root->ants || f)
	{
		j = -1;
		f = 0;
		if (root->iter_num)
			ln_print(1, root->iter_num++, "iter");
		while (++j < root->num_best)
			line_tap(root, &f, &i, j);
		if (i > root->ants && !f && (root->iter_num))
			ft_putendl("END");
		if (i <= root->ants || f)
			ft_putstr("\n");
	}
}
