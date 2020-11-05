/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:33:39 by erandal           #+#    #+#             */
/*   Updated: 2020/11/05 15:35:28 by erandal          ###   ########.fr       */
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
	i = -1;
	while (++i < w->first->way_l)
	{
		w = w->next;
	}
	w = w->first;
	return (w);
}

void	clear_way(t_lemon *root)
{
	int		i;
	
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
		if (check_way_i(root, rt) != 0)
		{
			root->id_links[i]->way_num = 9999999;
			return (0);
		}
		root->way_n = rt;
		return (1);
	}
	else
		while (++j < root->id_links[i]->link_num)
		{
			if (root->id_links[i]->link[j]
				&& root->id_links[i]->link[j]->way_num >= rt)
			{
				root->way[rt] = root->id_links[i];
				if (adventure(root,
					root->id_links[i]->link[j]->id_ln_i, ed, rt + 1))
					return (1);
			}
		}
	return (0);
}

int		bfs(t_lemon *root)
{
	int i;
	int st;
	int ed;

	i = -1;
	while (++i < root->room_num)
		if (root->id_links[i]->room_status == 1)
			st = i;
		else if (root->id_links[i]->room_status == 2)
			ed = i;
	clear_way(root);
	root->all_ways = (t_ways **)malloc(sizeof(t_ways *) * root->room_num);
	if (root->all_ways == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	root->ways_num = 0;
	while (1)
	{
		if (adventure(root, st, ed, 0) == 0)
			break ;
		root->all_ways[root->ways_num++] = save_way(root);
		clear_way(root);
	}
	sort_b(root);
	return (1);
}
