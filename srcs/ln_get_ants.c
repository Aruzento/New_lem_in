/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_get_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:41:52 by erandal           #+#    #+#             */
/*   Updated: 2020/11/10 14:49:29 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	err_get_map(t_lemon *root)
{
	if (root->err_f)
		ft_putendl_fd("\033[31;1mFile error:\033[0m Empty or wrong map!", 2);
	else
		ft_putendl_fd("ERROR", 2);
	full_free(root);
	exit(2);
}

int		get_ants(t_lemon *root)
{
	if (get_next_line(0, &root->line) <= 0)
		err_get_map(root);
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
