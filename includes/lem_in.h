#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <fcntl.h>

# define HASH_SIZE 4096

// ─────────────────────────────────────── STRUCTS ───────────────────────────────────────

typedef struct s_room t_room;

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
	t_link	*links;			// adjacency list
	t_room	*prev;			// for path backtracking
	t_room	*next;			// hash collision chain
	t_room	*all_next;		// master list for free
};

typedef struct s_data
{
	int		ant_count;
	t_room	*hash_table[HASH_SIZE];
	t_room	*rooms;
	t_room	*start;
	t_room	*end;
}	t_data;

typedef struct s_ant {
	int	id;
	int	pos;
}	t_ant;


typedef struct s_qnode {
	t_room *room;
	struct s_qnode *next;
}	t_qnode;


// ─────────────────────────────────────── PARSING ───────────────────────────────────────

void			read_input(t_data *data, char **av);
int				parse_ants(char *line, t_data *data);
int				parse_room(char *line, t_data *data, t_vars *var);
int				parse_link(char *line, t_data *data);
unsigned int	hash(const char *s);
int				parse_input(int ac, char **av, t_data *data);

// ─────────────────────────────────────── EXECUTION ───────────────────────────────────────

int				bfs_find_path(t_data *data);
t_room			**build_path_array(t_room *end, int *len_out);
void			simulate_ants(t_room **path, int path_len, int ant_count);
int				run_simulation(t_data *data);

// ─────────────────────────────────────── UTILS ───────────────────────────────────────

void			free_split(char **arr);
void			cleanup_data(t_data *data);
void			print_map_debug(t_data *data);
int				is_number(const char *str);

// ─────────────────────────────────────── DEBUG ───────────────────────────────────────

void			print_path_reverse(t_room *end);
void			print_path_forward(t_room **path, int len);
void			run_debug_tests(t_data *data, t_room **path, int path_len);

#endif
