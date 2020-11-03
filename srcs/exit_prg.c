/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:51:18 by erandal           #+#    #+#             */
/*   Updated: 2020/11/03 13:30:09 by erandal          ###   ########.fr       */
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
	while (++i < root->max_x + 2)
		ft_memdel((void **)(&root->mtrx[i]));
	ft_memdel((void **)(&root->mtrx));
	i = -1;
	while (++i < root->room_num)
	{
		ft_memdel((void **)(&root->id_links[i]->name));
		ft_memdel((void **)(&root->id_links[i]));
	}
	ft_memdel((void **)(&root->u_id));
	ft_memdel((void **)(&root->best_ways));
	ft_strdel(&root->line);
	ft_memdel((void **)(&root));
}

void	err_exit(t_lemon *root, char *error_msg)
{
	char	*tmp;

	if (!errno)
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
		ft_putendl_fd(error_msg, 2);
		exit(2);
	}
	else
		perror(error_msg);
}
