/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:08:56 by erandal           #+#    #+#             */
/*   Updated: 2020/11/05 16:22:32 by erandal          ###   ########.fr       */
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
void	check_way(t_lemon *root, int i)
{
	int		j;
	int		f;
	t_ways	*w;
	t_ways	*d;

	j = -1;
	w = root->all_ways[i]->first;
	if ((w->way_l - 2) > root->ants)
		return ;
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
			root->mtr[i][j] = '1';
	}
	return ;
}

void	del_w(t_lemon *root, int k)
{
	int i;
	int j;

	i = -1;
	while (++i < root->ways_num)
	{
		j = -1;
		if (root->mtr[k][i] == '1')
			while (++j < root->ways_num)
				if ((root->mtr[k][j] == '1')
					&& (root->mtr[i][j] == '0'))
					root->mtr[k][j] = '0';
	}
}

void summing_i(t_lemon *root, int i, int *num, int *sum)
{
	int j;

	*sum = 0;
	j = -1;
	*num = 0;
	while (++j < root->ways_num)
		if (root->mtr[i][j] == '1')
		{
			(*sum) += root->all_ways[j]->first->way_l;
			(*num)++;
		}
}

int	the_best(t_lemon *root, int *sum, int *num)
{
	int i;
	int j;
	int min;
	int best;

	i = -1;
	best = 0;
	min = 99999999;
	while (++i < root->ways_num)
	{
		summing_i(root, i, &(num[i]), &(sum[i]));
		j = -1;
		while (++j < root->ways_num)
		{
			if (num[i] == 0)
				break ;
			if (root->mtr[i][j] == '1'
				&& (((root->ants / num[i]) + ((sum[i] / num[i]) - 2))
				< root->all_ways[j]->first->way_l))
				root->mtr[i][j] = '0';
		}
		summing_i(root, i, &(num[i]), &(sum[i]));
		printf("f[%i] = %i\n", i, (root->ants / num[i]) + ((sum[i] / num[i]) - 2));
		if ((root->ants / num[i]) + ((sum[i] / num[i]) - 2) < min)
		{
			min = (root->ants / num[i]) + ((sum[i] / num[i]) - 2);
			best = i;
		}
	}
	return (best);
}

void	chose_ways(t_lemon *root)
{
	int i;
	int j;

	i = -1;
	if (!(root->mtr = (char **)malloc(sizeof(char *) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	if (!(root->sum_way = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	if (!(root->num = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	if (!(root->best_ways = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	while (++i < root->ways_num)
	{
		j = -1;
		root->mtr[i] = ft_strnew(root->ways_num);
		while (++j < root->ways_num)
			root->mtr[i][j] = '0';
	}
	i = -1;
	while (++i < root->ways_num)
	{
		check_way(root, i);
		root->mtr[i][i] = '1';
	}
	i = -1;
	while (++i < root->ways_num)
		del_w(root, i);
	root->best_ways[0] = the_best(root, root->sum_way, root->num);
	root->num_best = 0;
	i = -1;
	while (++i < root->ways_num)
	{
		if (root->mtr[root->best_ways[0]][i] == '1')
			root->best_ways[root->num_best++] = i;
	}
}
