/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:58:41 by erandal           #+#    #+#             */
/*   Updated: 2020/11/06 15:52:27 by erandal          ###   ########.fr       */
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
	if (root->min_x < 0)
		root->min_x *= -1;
	if (root->min_y < 0)
		root->min_y *= -1;
	root->mtrx = (char **)malloc(sizeof(char *) * (root->max_x + root->min_x + 2));
	while (++i <= root->max_x + root->min_x + 2)
	{
		j = -1;
		root->mtrx[i] = (char *)malloc(sizeof(char) * (root->max_y + root->min_y + 2));
		while (++j <= root->max_y + root->min_y)
			root->mtrx[i][j] = '0';
	}
	i = -1;
	while (++i < root->room_num)
	{
		if (root->id_links[i]->x_coord < 0)
			root->id_links[i]->x_coord = (root->id_links[i]->x_coord * -1) + root->max_x;
		if (root->id_links[i]->y_coord < 0)
			root->id_links[i]->y_coord = (root->id_links[i]->y_coord * -1) + root->max_y;
		if (root->mtrx[root->id_links[i]->x_coord]
			[root->id_links[i]->y_coord] != '0')
			err_exit(root, "\033[31;1mError: Same coords!\033[0m");
		else
			root->mtrx[root->id_links[i]->x_coord]
			[root->id_links[i]->y_coord] = '1';
	}
	if (!root->start || !root->end)
		err_exit(root, "\033[31;1mError: No start or end!\033[0m");
}
