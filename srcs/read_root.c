/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:58:41 by erandal           #+#    #+#             */
/*   Updated: 2020/11/06 16:55:46 by erandal          ###   ########.fr       */
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
