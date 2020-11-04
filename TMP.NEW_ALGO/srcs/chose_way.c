/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:08:56 by erandal           #+#    #+#             */
/*   Updated: 2020/11/04 18:49:46 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_way_i(t_lemon *root, int rt)
{
	int j;
	int k;
	t_ways *w;
	
	j = -1;
	while (++j < root->ways_num)
	{
		w = root->all_ways[j]->first->next;
		k = 0;
		while (++k < rt)
		{
			if (root->way[k] != w->s_way)
				break ;
			w = w->next;
		}
		if (k == rt && root->way[k] == w->s_way)
			return (1);
	}
	return (0);
}

int		save_id(t_lemon *root, int i)
{
	int		j;
	t_ways	*w;

	j = -1;
	w = root->all_ways[i];
	while (++j < root->all_ways[i]->way_l - 1)
	{
		if (w->s_way->marker == 0
			|| ((w->s_way->id_ln_i == w->first->s_way->id_ln_i)
			|| (w->s_way->id_ln_i == w->last->s_way->id_ln_i)))
		{
			root->u_id[root->u_id_n++] = w->s_way->id_ln_i;
			w->s_way->marker = 1;
		}
		else
			return (0);
		w = w->next;
	}
	return (1);
}

void	check_way(t_lemon *root, int i, char *mtr)
{
	int		j;
	int		f;
	t_ways	*w;
	t_ways	*d;

	j = -1;
	w = root->all_ways[i]->first;
	while (++j < w->first->way_l)
		w = w->next;
	w = root->all_ways[i]->first;
	if ((w->way_l - 2) > root->ants)
		return ;
	j = -1;
	while (++j < root->ways_num)
	{
		f = 0;
		w = root->all_ways[i]->first->next;
		while (w->s_way != w->last->s_way)
		{
			d = root->all_ways[j]->first->next;
			while (d->s_way != d->last->s_way)
			{
				if (w->s_way == d->s_way)
				{
					f++;
					break ;
				}
				d = d->next;
			}
			if (f)
				break ;
			w = w->next;
		}
		if (!f)
			mtr[j] = '1';
	}
	return ;
}

void	chose_ways(t_lemon *root)
{
	int i;
	int j;
	int num;
	int min;
	int best;
	int *sum_way;
	char **mtr;

	i = -1;
	min = 999999;
	if (!(mtr = (char **)malloc(sizeof(char *) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	while (++i < root->ways_num)
	{
		mtr[i] = ft_strnew(root->ways_num);
		j = -1;
		while (++j < root->ways_num)
			mtr[i][j] = '0';
	}
	if (!(sum_way = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	if (!(root->best_ways = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	i = -1;
	while (++i < root->ways_num)
		check_way(root, i, mtr[i]);
	i = -1;
	while (++i < root->ways_num)
	{
		j = -1;
		sum_way[i] = 0;
		num = 0;
		while (++j < root->ways_num)
			if (mtr[i][j] == '1')
			{
				sum_way[i] += root->all_ways[i]->first->way_l;
				num++;
			}
		if (num)
			sum_way[i] /= num;
		if (sum_way[i] < min)
			best = i;
	}
	root->num_best = 0;
	i = -1;
	root->best_ways[root->num_best++] = best;
	while (++i < root->ways_num)
		if (mtr[best][i] == '1')
			root->best_ways[root->num_best++] = i;
}
