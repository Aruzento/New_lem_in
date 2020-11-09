/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:48:29 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 14:36:29 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		take_coord(t_lemon *root, int *pos, t_rooms *room, int *coord)
{
	char *tmp;

	tmp = get_next_word(root->line, pos);
	if (li_atoi(tmp, coord))
		return (err_room(room, tmp));
	ft_strdel(&tmp);
	return (0);
}

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
	root->err_f = 0;
	root->line_num = 0;
	root->best_ways = NULL;
	root->all_ways = NULL;
}

int		main(int av, char **ac)
{
	t_lemon	*root;

	root = (t_lemon *)malloc(sizeof(t_lemon));
	root->input_lines = (char **)malloc(sizeof(char *) * 100000);
	initial_root(root);
	if (av == 2 && ac[1][0] == '-')
	{
		if (ac[1][1] == 'n' || ac[1][2] == 'n')
			root->iter_num = 1;
		if (ac[1][1] == 'e' || ac[1][2] == 'e')
			root->err_f = 1;
	}
	read_map(root);
	bfs(root);
	chose_ways(root);
	get_result(root);
	full_free(root);
	return (0);
}
