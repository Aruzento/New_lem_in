/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:48:29 by erandal           #+#    #+#             */
/*   Updated: 2020/11/03 14:35:35 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initial_root(t_lemon *root)
{
	int i;

	i = 0;
	while (i++ < 100000)
	{
		root->id_links[i] = NULL;
		root->linkd_n[i] = 0;
	}
	root->start = 0;
	root->end = 0;
	root->ants = 0;
	root->room_num = 0;
	root->cmd = 0;
	root->num_list = 0;
	root->iter_num = 0;
	root->max_x = -1111;
	root->max_y = -1111;
	root->line_num = 0;
	root->u_id = NULL;
	root->best_ways = NULL;
	root->mtrx = NULL;
	root->all_ways = NULL;
}

int		main(int av, char **ac)
{
	t_lemon	*root;

	root = (t_lemon *)malloc(sizeof(t_lemon));
	initial_root(root);
	if (av == 2 && ac[1][0] == '-')
	{
		if (ac[1][1] == 'n')
			root->iter_num = 1;
	}
	read_map(root);
	bfs(root);
	chose_ways(root);
	get_result(root);
	full_free(root);
	return (0);
}
