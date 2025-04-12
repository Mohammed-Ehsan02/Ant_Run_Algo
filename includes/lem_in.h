#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include <fcntl.h>

# define HASH_SIZE 4096 

typedef struct s_room t_room;

typedef struct s_vars
{
	int fd;
	int is_start;
	int	is_end;
	int parsing_rooms;
	int	ant_parsed;
	char **split;
	int hash_index;
	t_room	*room1;
	t_room	*room2;
	char *tmp;
	char *line;
}	t_vars;


typedef struct s_link {
	t_room *room;
	struct s_link *next;
} t_link;

struct s_room {
	char	*name;
	int		x;
	int		y;
	int		is_start;
	int		is_end;
	int		visited;
	t_link	*links;			// adjacency list for BFS
	t_room	*prev;			// for backtracking path
	t_room	*next;			// for hash collision
	t_room	*all_next;		// for freeing and full traversal
};

typedef struct s_data {
	int		ant_count;
	int		got_start;
	int		got_end;
	t_room	*hash_table[HASH_SIZE];
	t_room	*rooms;			// full list of all rooms
	t_room	*start;
	t_room	*end;
} t_data;


// Parsing
int				is_number(const char *str);
void			read_input(t_data *data, char **av);
unsigned int	hash(const char *s);
int				parse_ants(char *line, t_data *data);
int				parse_room(char *line, t_data *data, t_vars *var);
int				parse_link(char *line, t_data *data);
int				parse_input(int ac, char **av, t_data *data);
int				add_room(char *line, int is_start, int is_end);
int				add_link(char *line);
unsigned int 	hash(const char *str);
t_room			*get_room(const char *name);

// Execution
void	run_simulation(void);
void	reset_visited(void);
void	find_paths(void);

// Utils
void	free_split(char **arr);
void	cleanup_data(t_data *data);
void	print_map_debug(t_data *data);

#endif
