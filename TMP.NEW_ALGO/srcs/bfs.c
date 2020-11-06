/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:33:39 by erandal           #+#    #+#             */
/*   Updated: 2020/11/06 14:59:53 by erandal          ###   ########.fr       */
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
	printf("a\n");
	w = re_link(root, w);
	printf("b\n");
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
	printf("c\n");
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
		root->way_n = rt;
		printf("%i\n", root->ways_num);
		root->all_ways[root->ways_num++] = save_way(root);
		printf("d\n");
		root->id_links[i]->way_num = 9999999;
		return (0);
	}
	else
		while (++j < root->id_links[i]->link_num)
		{
			if (root->id_links[i]->link[j]
				&& root->id_links[i]->link[j]->way_num >= rt
				&& rt + 1 < root->ants)
			{
				root->way[rt] = root->id_links[i];
				adventure(root,	root->id_links[i]->link[j]->id_ln_i, ed, rt + 1);
			}
		}
	root->id_links[i]->way_num = 9999999;
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
	root->all_ways = (t_ways **)malloc(sizeof(t_ways *) * (root->room_num * root->room_num));
	if (root->all_ways == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	root->ways_num = 0;
	while (root->ways_num < root->room_num)
		if (adventure(root, st, ed, 0) == 0)
			break ;
	sort_b(root);
	return (1);
}
