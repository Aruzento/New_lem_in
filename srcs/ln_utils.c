/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:39:43 by erandal           #+#    #+#             */
/*   Updated: 2020/11/09 15:01:07 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*get_next_word(char *tmp, int *pos)
{
	char	*str;
	int		i;

	i = 0;
	while (tmp[*pos + i] && tmp[*pos + i] != ' ')
		i++;
	str = ft_strsub(tmp, *pos, i);
	*pos += i + 1;
	return (str);
}

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

int		li_atoi(char *line, int *ants)
{
	int		i;
	int		check;
	int		negative;

	if (!line)
		return (-1);
	i = 0;
	*ants = 0;
	check = 0;
	negative = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '-' || line[i] == '+')
		negative = (line[i++] == '-') ? 1 : 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		check++;
		*ants = (*ants * 10) + (line[i++] - '0');
	}
	if (negative)
		*ants *= -1;
	if (line[i] || check == 0)
		return (-1);
	return (0);
}

t_ways	*zero_way(t_lemon *root, t_ways *w, int i)
{
	w = (t_ways *)malloc(sizeof(t_ways));
	if (w == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	root->list_ways[root->num_list++] = w;
	w->s_way = root->way[i];
	w->ant = 0;
	w->s_way->marker = 0;
	w->first = w;
	w->next = NULL;
	return (w);
}

t_ways	*non_zero_way(t_lemon *root, t_ways *w, int i)
{
	w->next = (t_ways *)malloc(sizeof(t_ways));
	if (w == NULL)
		err_exit(root, "\033[31;1mError: Way malloc error!\033[0m");
	w->next->prev = w;
	w->next->first = w->first;
	w = w->next;
	root->list_ways[root->num_list++] = w;
	w->s_way = root->way[i];
	w->s_way->marker = 0;
	w->last = NULL;
	w->ant = 0;
	w->next = w->first;
	return (w);
}
