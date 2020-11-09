/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_get_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:51:03 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 17:43:24 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_rooms	*room_create(void)
{
	t_rooms *room;

	room = (t_rooms *)malloc(sizeof(t_rooms));
	room->link_num = 0;
	room->room_status = 0;
	room->marker = 0;
	return (room);
}

int		parse_rooms(t_lemon *root)
{
	int		pos;
	t_rooms	*room;
	int		i;

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
	room->id_ln_i = root->room_num;
	root->id_links[root->room_num++] = room;
	i = -1;
	while (++i < root->room_num - 1)
		if (!ft_strcmp(root->id_links[i]->name, room->name))
			return (-1);
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
	while ((ret = get_next_line(0, &root->line)))
	{
		if (root->line[0] == '#')
			parse_cmd(root);
		else if (ft_strchr(root->line, '-') && !(ft_strchr(root->line, ' ')))
		{
			get_links(root);
			return ;
		}
		else if ((root->room_num == 99999) || root->line[0] == 'L'
			|| parse_rooms(root) == -1)
			err_exit(root, "\033[31;1mError: Room line error!\033[0m");
		root->input_lines[root->line_num] = root->line;
		root->line_num++;
	}
	if (root->room_num == 0)
		err_exit(root, "\033[31;1mError: No rooms!\033[0m");
	err_exit(root, "\033[31;1mError: No links!\033[0m");
}
