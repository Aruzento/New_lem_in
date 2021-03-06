/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erandal <erandal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:55:38 by erandal           #+#    #+#             */
/*   Updated: 2020/11/12 14:53:55 by erandal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include "mlx.h"

typedef struct		s_rooms
{
	char			*name;
	int				room_status;
	int				id;
	int				id_ln_i;
	int				x_coord;
	int				y_coord;
	int				way_num;
	int				link_num;
	int				marker;
	struct s_rooms	*first;
	struct s_rooms	*last;
	struct s_rooms	*next;
	int				is_f;
	struct s_rooms	*link[100000];
}					t_rooms;

typedef struct		s_ways
{
	t_rooms			*s_way;
	int				ant;
	int				way_l;
	struct s_ways	*next;
	struct s_ways	*first;
	struct s_ways	*prev;
	struct s_ways	*last;
}					t_ways;

typedef struct		s_lemon
{
	int				print_res;
	int				iter_num;
	int				err_f;
	char			*line;
	int				line_num;
	int				cmd;
	int				start;
	int				end;
	int				ants;
	int				room_num;
	char			**input_lines;
	t_rooms			*id_links[100000];
	t_rooms			*linkd[100000];
	int				linkd_n[100000];
	t_rooms			*way[100000];
	int				way_n;
	t_ways			**all_ways;
	t_ways			*list_ways[100000];
	int				num_list;
	int				ways_num;
	int				*best_ways;
	int				num_best;
	int				u_id[100000];
	int				u_id_n;
}					t_lemon;

void				initial_root(t_lemon *root);
void				check_flags(t_lemon *root, int av, char **ac);
void				read_map(t_lemon *root);
int					get_ants(t_lemon *root);
int					li_atoi(char *line, int *ants);
int					check_int(int a, char c, int n);
char				*get_next_word(char *tmp, int *pos);
void				get_rooms(t_lemon *root);
void				name_valid(t_lemon *root, t_rooms *room);
int					generate_key(char *name);
void				create_link(t_lemon *root, t_rooms *room);
int					take_coord(t_lemon *root,
	int *pos, t_rooms *room, int *coord);
int					err_room(t_lemon *root, t_rooms *room, char *tmp);
void				get_links(t_lemon *root);
void				parse_cmd(t_lemon *root);
char				*get_next_link(char *tmp, int *pos);
int					bfs(t_lemon *root);
t_ways				*non_zero_way(t_lemon *root, t_ways *w, int i);
t_ways				*zero_way(t_lemon *root, t_ways *w, int i);
void				chose_ways(t_lemon *root);
void				get_result(t_lemon *root);
void				alt_print(t_lemon *root);
void				err_exit(t_lemon *gr, char *error_msg);
void				full_free(t_lemon *root);
void				show_status_t_lemon(t_lemon *root);
#endif
