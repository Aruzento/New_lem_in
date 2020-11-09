/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_rooms_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:46:12 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 19:59:20 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	name_valid(t_lemon *root, t_rooms *room)
{
	int	i;

	i = -1;
	if (ft_strchr(room->name, '-'))
	{
		err_room(root, room, NULL);
		err_exit(root, "\033[31;1mError: '-' char is forbidden!\033[0m");
	}
	while (room->name[++i])
		if ((int)(room->name[i]) < 0)
		{
			err_room(root, room, NULL);
			err_exit(root, "\033[31;1mError: RU char is forbidden!\033[0m");
		}
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

int		take_coord(t_lemon *root, int *pos, t_rooms *room, int *coord)
{
	char *tmp;

	tmp = get_next_word(root->line, pos);
	if (li_atoi(tmp, coord))
		return (err_room(root, room, tmp));
	ft_strdel(&tmp);
	return (0);
}

int		err_room(t_lemon *root, t_rooms *room, char *tmp)
{
	if (tmp != room->name)
		ft_strdel(&tmp);
	ft_strdel(&room->name);
	ft_memdel((void **)&room);
	root->room_num--;
	return (-1);
}

void	create_link(t_lemon *root, t_rooms *room)
{
	if (root->cmd)
	{
		room->room_status = root->cmd;
		if (root->cmd == 1)
			root->start++;
		else
			root->end++;
		root->cmd = 0;
	}
	if (root->linkd_n[room->id] == 0)
	{
		root->linkd[room->id] = room;
		root->linkd[room->id]->first = root->linkd[room->id];
		root->linkd[room->id]->last = root->linkd[room->id];
		root->linkd[room->id]->next = root->linkd[room->id]->first;
		root->linkd_n[room->id]++;
		return ;
	}
	root->linkd[room->id] = root->linkd[room->id]->last;
	root->linkd[room->id]->next = room;
	root->linkd[room->id]->next->first = root->linkd[room->id]->first;
	root->linkd[room->id]->first->last = root->linkd[room->id]->next;
	root->linkd[room->id]->next->next = root->linkd[room->id]->first;
	root->linkd[room->id] = root->linkd[room->id]->first;
	root->linkd_n[room->id]++;
}
