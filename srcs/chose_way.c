/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:08:56 by erandal           #+#    #+#             */
/*   Updated: 2020/11/08 17:49:54 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int		check_way(t_lemon *root, int i)
{
	int		j;
	t_ways	*w;

	j = -1;
	w = root->all_ways[i];
	while (++j < root->all_ways[i]->way_l - 1)
	{
		if (w->s_way->marker != 0
			&& (w->s_way->id_ln_i != w->first->s_way->id_ln_i)
			&& (w->s_way->id_ln_i != w->last->s_way->id_ln_i))
			return (0);
		w = w->next;
	}
	return (save_id(root, i));
}

void	chose_ways(t_lemon *root)
{
	int i;

	i = -1;
	if (!(root->best_ways = (int *)malloc(sizeof(int) * root->ways_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	root->num_best = 0;
	root->u_id_n = 0;
	while (++i < root->ways_num)
		if (check_way(root, i))
			root->best_ways[root->num_best++] = i;
}
