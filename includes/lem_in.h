/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:33 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:33 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>

# define HASH_SIZE 4096

// ─────────────────────────── STRUCTS ───────────────────────────

typedef struct s_room	t_room;

typedef struct s_vars
{
	int		fd;
	int		is_start;
	int		is_end;
	int		parsing_rooms;
	int		ant_parsed;
	char	**split;
	int		hash_index;
	t_room	*room1;
	t_room	*room2;
	char	*tmp;
	char	*line;
	int		start_found;
	int		end_found;
}	t_vars;

typedef struct s_link
{
	t_room			*room;
	struct s_link	*next;
}	t_link;

struct s_room
{
	char	*name;
	int		x;
	int		y;
	int		is_start;
	int		is_end;
	int		visited;
	int		used;
	t_link	*links;
	t_room	*prev;
	t_room	*next;
	t_room	*all_next;
};

typedef struct s_input_line
{
	char				*line;
	struct s_input_line	*next;
}	t_input_line;

typedef struct s_data
{
	int				ant_count;
	t_room			*hash_table[HASH_SIZE];
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_input_line	*input_lines;
}	t_data;

typedef struct s_ant
{
	int	id;
	int	pos;
}	t_ant;

typedef struct s_qnode
{
	t_room			*room;
	struct s_qnode	*next;
}	t_qnode;

typedef struct s_path
{
	t_room			**rooms;
	int				len;
	int				ants;
	struct s_path	*next;
}	t_path;

typedef struct s_paths
{
	t_path	*list;
	int		count;
	int		total_ants;
}	t_paths;

typedef struct s_mant
{
	int		id;
	int		path_idx;
	int		pos;
}	t_mant;

// ────────────────────────────── PARSING ──────────────────────────────

void			read_input(t_data *data, char **av);
int				parse_ants(char *line, t_data *data);
int				parse_room(char *line, t_data *data, t_vars *var);
int				parse_link(char *line, t_data *data);
unsigned int	hash(const char *s);
int				parse_input(int ac, char **av, t_data *data);

// ────────────────────────────── EXECUTION ──────────────────────────────

int				bfs_find_path(t_data *data);
t_room			**build_path_array(t_room *end, int *len_out);
int				run_simulation(t_data *data);

// ────────────────────────────── BFS_UTILS ──────────────────────────────

void			reset_bfs_flags(t_data *data);
void			reset_used_flags(t_data *data);
void			mark_path_used(t_room **path, int len);

// ────────────────────────────── PATH ──────────────────────────────

int				get_path_length(t_room *end);
t_path			*create_path_node(t_room **rooms, int len);
int				add_path_to_list(t_paths *paths, t_room **rooms, int len);

// ────────────────────────────── MULTIPATH ──────────────────────────────

t_paths			*init_paths(int ant_count);
t_paths			*find_all_paths(t_data *data);
void			free_path(t_path *path);
void			free_all_paths(t_paths *paths);

// ────────────────────────────── DISTRIBUTE ──────────────────────────────

int				calc_turns(t_path *path);
t_path			*find_best_path(t_path *list);
void			distribute_ants(t_paths *paths);
void			sort_paths_by_len(t_paths *paths);

// ────────────────────────────── SIMULATE ──────────────────────────────

void			simulate_multi(t_paths *paths);

// ────────────────────────────── SIM_UTILS ──────────────────────────────

t_path			*get_path_by_idx(t_paths *paths, int idx);
t_room			*get_ant_room(t_mant *ant, t_paths *paths);
int				room_occupied(t_room *r, t_mant *ants, int cnt, t_paths *p);
void			print_ant_move(int id, char *name, int *printed);

// ────────────────────────────── UTILS ──────────────────────────────

void			free_split(char **arr);
void			cleanup_data(t_data *data);
void			print_map_debug(t_data *data);
int				is_number(const char *str);
void			print_original_map(t_input_line *head);
void			clean_activate(t_data *data, t_vars *var, char *err);
void			free_queue(t_qnode *head);

// ────────────────────────────── DEBUG ──────────────────────────────

void			print_path_reverse(t_room *end);
void			print_path_forward(t_room **path, int len);
void			run_debug_tests(t_data *data, t_room **path, int path_len);

#endif
