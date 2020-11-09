/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_get_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:41:52 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 18:43:06 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_ants(t_lemon *root)
{
	if (!get_next_line(0, &root->line))
		err_exit(root, "\033[31;1mError: Empty or wrong map!\033[0m");
	if (root->line[0] == '#')
		return (0);
	if (li_atoi(root->line, &root->ants))
		err_exit(root, "\033[31;1mError: Atoi is incorrect!\033[0m");
	if (root->ants < 0)
		err_exit(root, "\033[31;1mError: Ants can't be less then 0!\033[0m");
	root->input_lines[root->line_num] = ft_strdup(root->line);
	ft_strdel(&(root->line));
	root->line_num++;
	return (0);
}
