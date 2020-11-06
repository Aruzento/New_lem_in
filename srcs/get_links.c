/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:03:34 by erandal           #+#    #+#             */
/*   Updated: 2020/11/06 16:59:56 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_next_link(char *tmp, int *pos)
{
	char	*str;
	int		i;

	i = 0;
	while (tmp[*pos + i] && tmp[*pos + i] != '-')
		i++;
	str = ft_strsub(tmp, *pos, i);
	*pos += i + 1;
	return (str);
}

t_rooms	*get_id_name(t_lemon *root, char *tmp, int id)
{
	int	i;

	i = -1;
	while (++i < root->linkd_n[id])
	{
		if (!ft_strcmp(root->linkd[id]->name, tmp))
			break ;
		root->linkd[id] = root->linkd[id]->next;
	}
	ft_strdel(&tmp);
	if (i == root->linkd_n[id])
		err_exit(root, "\033[31;1mError: Room_Id error!\033[0m");
	return (root->linkd[id]);
}

void	check_same(t_lemon *root, t_rooms *room, t_rooms *link)
{
	int i;

	i = -1;
	while (++i < room->link_num)
		if (room->link[i] == link)
			if (!ft_strcmp(room->link[i]->name, link->name))
				err_exit(root, "\033[31;1mError: Double link!\033[0m");
	if (room == link)
		err_exit(root, "\033[31;1mError: Wrong link!\033[0m");
}

int		parse_links(t_lemon *root)
{
	int		pos;
	char	*tmp;
	t_rooms	*room[2];
	int		id[2];

	pos = 0;
	tmp = get_next_link(root->line, &pos);
	id[0] = generate_key(tmp);
	if (!root->linkd[id[0]])
		err_exit(root, "\033[31;1mError: Room_Id error!\033[0m");
	room[0] = get_id_name(root, tmp, id[0]);
	tmp = get_next_link(root->line, &pos);
	id[1] = generate_key(tmp);
	if (!root->linkd[id[1]])
		err_exit(root, "\033[31;1mError: Room_Id error!\033[0m");
	room[1] = get_id_name(root, tmp, id[1]);
	check_same(root, room[0], room[1]);
	check_same(root, room[1], room[0]);
	room[0]->link[room[0]->link_num] = room[1];
	room[1]->link[room[1]->link_num] = room[0];
	room[0]->link_num++;
	room[1]->link_num++;
	root->linkd[id[1]] = root->linkd[id[1]]->first;
	root->linkd[id[0]] = root->linkd[id[0]]->first;
	return (0);
}

void	get_links(t_lemon *root)
{
	int	ret;

	if (!ft_strchr(root->line, '-') || parse_links(root))
		err_exit(root, "\033[31;1mError: Link line error!\033[0m");
	ft_strdel(&root->line);
	root->line_num++;
	while ((ret = get_next_line(0, &root->line)))
	{
		//ft_putstr(root->line);
		//ft_putchar('\n');
		if (root->line[0] == '#')
			parse_cmd(root);
		else if (!ft_strchr(root->line, '-') || parse_links(root))
			err_exit(root, "\033[31;1mError: Incorrect link line!\033[0m");
		ft_strdel(&root->line);
		root->line_num++;
	}
}
