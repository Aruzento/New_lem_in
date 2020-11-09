/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:01:40 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 15:06:51 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lemin.h"

t_ways	*re_link(t_lemon *root, t_ways *w)
{
	int		i;

	i = -1;
	while (++i <= root->way_n)
		if (i == 0)
			w = zero_way(root, w, i);
		else
			w = non_zero_way(root, w, i);
	w->first->way_l = i;
	return (w);
}

t_ways	*save_way(t_lemon *root)
{
	t_ways	*w;
	int		i;

	w = NULL;
	w = re_link(root, w);
	w->first->last = w;
	w->first->prev = w;
	i = -1;
	w = w->first;
	while (++i <= root->way_n)
	{
		w->last = w->first->last;
		w = w->next;
	}
	w = w->first;
	return (w);
}

void	clear_way(t_lemon *root)
{
	int		i;
	int		j;
	t_ways	*w;

	w = root->all_ways[root->ways_num - 1];
	j = -1;
	while (++j < w->first->way_l)
	{
		i = -1;
		while (++i < w->s_way->link_num)
			if (w->s_way->link[i]
				&& (w->s_way->link[i]->id_ln_i == w->next->s_way->id_ln_i))
				w->s_way->link[i] = NULL;
		w = w->next;
	}
	i = -1;
	while (++i < root->room_num)
		root->id_links[i]->way_num = 9999999;
}

int		adventure(t_lemon *root, int i, int ed, int rt)
{
	int j;
	int res;

	res = 0;
	j = -1;
	root->id_links[i]->way_num = rt;
	if (i == ed)
	{
		root->way[rt] = root->id_links[i];
		root->way_n = rt;
		return (1);
	}
	else
		while (++j < root->id_links[i]->link_num)
			if (root->id_links[i]->link[j]
				&& root->id_links[i]->link[j]->way_num > rt)
				if (adventure(root,
					root->id_links[i]->link[j]->id_ln_i, ed, rt + 1))
				{
					res++;
					root->way[rt] = root->id_links[i];
				}
	return ((res) ? 1 : 0);
}

int		bfs(t_lemon *root)
{
	int i;
	int st;
	int ed;

	i = -1;
	if (!(root->all_ways = (t_ways **)malloc(sizeof(t_ways *) * root->room_num)))
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	while (++i < root->room_num)
	{
		if (root->id_links[i]->room_status == 1)
			st = i;
		if (root->id_links[i]->room_status == 2)
			ed = i;
		root->id_links[i]->way_num = 99999;
	}
	while (1)
	{
		if (adventure(root, st, ed, 0) == 0)
			break ;
		root->all_ways[root->ways_num++] = save_way(root);
		clear_way(root);
	}
	return (1);
}
