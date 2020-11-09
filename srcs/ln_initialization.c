/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:19:21 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 17:17:29 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initial_root(t_lemon *root)
{
	int i;

	i = 0;
	root->ways_num = 0;
	root->start = 0;
	root->end = 0;
	root->ants = 0;
	root->room_num = 0;
	root->cmd = 0;
	root->num_list = 0;
	root->num_best = 0;
	root->u_id_n = 0;
	root->line_num = 0;
	root->best_ways = NULL;
	root->all_ways = NULL;
	if (!(root->input_lines = (char **)malloc(sizeof(char *) * 100000)))
		err_exit(root, "\033[31;1mError: Malloc error!\033[0m");
	while (i++ < 100000)
	{
		root->id_links[i] = NULL;
		root->linkd_n[i] = 0;
	}
}

void	check_flags(t_lemon *root, int av, char **ac)
{
	int i;
	int j;

	i = 0;
	root->iter_num = 0;
	root->err_f = 0;
	root->print_res = 0;
	while (++i < av)
	{
		j = 0;
		if (ac[i][j] != '-')
			err_exit(root, "\033[31;1mError: Wrong flag!\033[0m");
		while (ac[i][++j])
		{
			if (ac[i][j] == 'n')
				root->iter_num = 1;
			else if (ac[i][j] == 'e')
				root->err_f = 1;
			else if (ac[i][j] == 'E')
				root->print_res = 1;
			else if (ac[i][j] == 'N')
				root->print_res = 2;
		}
	}
}
