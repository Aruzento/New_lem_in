/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:46:37 by erandal           #+#    #+#             */
/*   Updated: 2020/11/04 17:52:43 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms	*room_create(void)
{
	t_rooms *room;

	room = (t_rooms *)malloc(sizeof(t_rooms));
	room->link_num = 0;
	room->room_status = 0;
	return (room);
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

int		parse_rooms(t_lemon *root)
{
	int		pos;
	t_rooms	*room;

	room = room_create();
	pos = 0;
	if (!(room->name = get_next_word(root->line, &pos)))
		return (err_room(room, room->name));
	name_valid(root, room);
	room->id = generate_key(room->name);
	if (take_coord(root, &pos, room, &room->x_coord))
		return (-1);
	if (take_coord(root, &pos, room, &room->y_coord))
		return (-1);
	root->max_x = (root->max_x < room->x_coord) ? room->x_coord : root->max_x;
	root->max_y = (root->max_y < room->y_coord) ? room->y_coord : root->max_y;
	root->id_links[root->room_num++] = room;
	room->id_ln_i = root->room_num - 1;
	create_link(root, room);
	if (root->line[pos - 1])
		return (err_room(room, room->name));
	return (0);
}

void	parse_cmd(t_lemon *root)
{
	if (!ft_strcmp(root->line, "##start") || !ft_strcmp(root->line, "##end"))
	{
		if (root->cmd)
			err_exit(root, "\033[31;1mError: Command error!\033[0m");
		else
		{
			root->cmd = (!ft_strcmp(root->line, "##start")) ? 1 : 2;
			if ((root->cmd == 1 && root->start)
				|| (root->cmd == 2 && root->end))
				err_exit(root, "\033[31;1mError: Command error!\033[0m");
		}
	}
}

void	get_rooms(t_lemon *root)
{
	int ret;

	ret = 0;
	root->line_num++;
	while ((ret = get_next_line(0, &root->line)))
	{
		/*ft_putstr(root->line);
		ft_putchar('\n');*/
		if (root->line[0] == '#')
			parse_cmd(root);
		else if (ft_strchr(root->line, '-'))
		{
			get_links(root);
			return ;
		}
		else if (root->line[0] == 'L' || parse_rooms(root) == -1)
			err_exit(root, "\033[31;1mError: Room line error!\033[0m");
		ft_strdel(&root->line);
		root->line_num++;
	}
	if (root->room_num == 0)
		err_exit(root, "\033[31;1mError: No rooms!\033[0m");
	err_exit(root, "\033[31;1mError: No links!\033[0m");
}
