/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:55:09 by erandal           #+#    #+#             */
/*   Updated: 2020/10/27 22:50:23 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_ways	*zero_way(t_lemon *root, t_ways *w, int i)
{
	w = (t_ways *)malloc(sizeof(t_ways));
	if (w == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	root->list_ways[root->num_list++] = w;
	w->s_way = root->way[i];
	w->ant = 0;
	w->s_way->marker = 0;
	w->first = w;
	w->next = NULL;
	return (w);
}

t_ways	*non_zero_way(t_lemon *root, t_ways *w, int i)
{
	w->next = (t_ways *)malloc(sizeof(t_ways));
	if (w == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	w->next->prev = w;
	w->next->first = w->first;
	w = w->next;
	root->list_ways[root->num_list++] = w;
	w->s_way = root->way[i];
	w->s_way->marker = 0;
	w->last = NULL;
	w->ant = 0;
	w->next = w->first;
	return (w);
}

int		generate_key(char *name)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (++i < (int)ft_strlen(name))
		num += (int)(name[i]);
	return (num % 100000);
}
