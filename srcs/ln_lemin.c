/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:34:44 by erandal           #+#    #+#             */
/*   Updated: 2020/11/10 14:38:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	read_map(t_lemon *root)
{
	int i;
	int j;

	get_ants(root);
	get_rooms(root);
	i = -1;
	while (++i < root->room_num)
	{
		j = i;
		while (++j < root->room_num)
			if (root->id_links[i]->x_coord == root->id_links[j]->x_coord
			&& root->id_links[i]->y_coord == root->id_links[j]->y_coord)
				err_exit(root, "\033[31;1mError: Same coords!\033[0m");
	}
	if (!root->start || !root->end)
		err_exit(root, "\033[31;1mError: No start or end!\033[0m");
}

int		main(int av, char **ac)
{
	t_lemon	*root;

	root = (t_lemon *)malloc(sizeof(t_lemon));
	initial_root(root);
	check_flags(root, av, ac);
	read_map(root);
	bfs(root);
	chose_ways(root);
	if (root->print_res == 0)
		get_result(root);
	else if (root->print_res == 1)
		alt_print(root);
	full_free(root);
	return (0);
}
