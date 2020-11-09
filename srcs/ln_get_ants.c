/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_get_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:41:52 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 20:09:59 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_ants(t_lemon *root)
{
	if (!get_next_line(0, &root->line))
		err_exit(root, "\033[31;1mError: Empty or wrong map!\033[0m");
	if (root->line[0] == '#')
	{
		root->input_lines[root->line_num++] = ft_strdup(root->line);
		ft_strdel(&(root->line));
		while (get_next_line(0, &root->line))
			if (root->line[0] != '#')
				break ;
			else
			{
				root->input_lines[root->line_num++] = ft_strdup(root->line);
				ft_strdel(&(root->line));
			}
	}
	if (li_atoi(root->line, &root->ants))
		err_exit(root, "\033[31;1mError: Atoi is incorrect!\033[0m");
	if (root->ants < 0)
		err_exit(root, "\033[31;1mError: Ants can't be less then 0!\033[0m");
	root->input_lines[root->line_num++] = ft_strdup(root->line);
	ft_strdel(&(root->line));
	return (0);
}
