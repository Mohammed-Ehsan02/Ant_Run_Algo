#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

# define HASH_SIZE 1024

typedef struct s_room t_room;

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
int		parse_input(t_data *data);
int		parse_ants(char *line, t_data *data);
int		add_room(char *line, t_data *data, int is_start, int is_end);
int		add_link(char *line, t_data *data);
unsigned int hash(const char *str);
t_room	*get_room(t_data *data, const char *name);

// Execution
void	run_simulation(t_data *data);
void	reset_visited(t_data *data);
void	find_paths(t_data *data);

// Utils
// void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	free_split(char **arr);
void	free_all(t_data *data);

#endif
