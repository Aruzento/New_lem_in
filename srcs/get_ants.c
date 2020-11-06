/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:58:25 by erandal           #+#    #+#             */
/*   Updated: 2020/11/06 16:11:59 by erandal          ###   ########.fr       */
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

int		get_ants(t_lemon *root)
{
	root->line_num++;
	if (!get_next_line(0, &root->line))
		err_exit(root, "\033[31;1mError: Empty or wrong map!\033[0m");
	/*ft_putstr(root->line);
	ft_putchar('\n');*/
	if (root->line[0] == '#')
		return (0);
	if (li_atoi(root->line, &root->ants))
		err_exit(root, "\033[31;1mError: Atoi is incorrect!\033[0m");
	if (root->ants < 0)
		err_exit(root, "\033[31;1mError: Ants can't be less then 0!\033[0m");
	ft_strdel(&root->line);
	return (0);
}
