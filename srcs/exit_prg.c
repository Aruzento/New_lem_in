/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:51:18 by erandal           #+#    #+#             */
/*   Updated: 2020/11/08 18:37:05 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	full_free(t_lemon *root)
{
	int		i;

	i = -1;
	while (++i < root->num_list)
		ft_memdel((void **)(&root->list_ways[i]));
	ft_memdel((void **)(&root->all_ways));
	i = -1;
	while (++i < root->room_num)
	{
		ft_memdel((void **)(&root->id_links[i]->name));
		ft_memdel((void **)(&root->id_links[i]));
	}
	i = -1;
	while (++i < root->line_num)
		ft_strdel(&(root->input_lines[i]));
	ft_memdel((void **)&root->input_lines);
	ft_memdel((void **)(&(root->best_ways)));
	ft_memdel((void **)(&root));
}

void	err_exit(t_lemon *root, char *error_msg)
{
	char	*tmp;

	if (!errno && root->err_f)
	{
		ft_putstr_fd("\033[31;1m/ln:\033[0m", 2);
		tmp = ft_itoa(root->line_num);
		ft_putstr_fd(tmp, 2);
		ft_strdel(&tmp);
		ft_putstr_fd("\033[31;1m: \033[0m", 2);
	}
	full_free(root);
	if (!errno)
	{
		tmp = "ERROR";
		if (root->err_f)
			ft_putendl_fd(error_msg, 2);
		else
			ft_putendl_fd("ERROR", 2);
		ft_memdel((void **)(root));
	}
	else
		perror(error_msg);
	exit(2);
}
