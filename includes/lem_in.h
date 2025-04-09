#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define HASH_SIZE 1024

typedef struct s_room t_room;

typedef struct s_link {
	t_room *room;
	struct s_link *next;
} t_link;

struct s_room {
	char *name;
	int x;
	int y;
	int is_start;
	int is_end;
	int visited;
	t_link *links;
	t_room *prev;
	t_room *next; // hash collision
};

// Parsing
int		parse_input(void);
int		add_room(char *line, int is_start, int is_end);
int		add_link(char *line);
unsigned int hash(const char *str);
t_room	*get_room(const char *name);

// Execution
void	run_simulation(void);
void	reset_visited(void);
void	find_paths(void);

// Utils
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	free_split(char **arr);

#endif
