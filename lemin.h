#ifndef LEMIN_H
# define STRUCTS_H

#include "libft/libft.h"

typedef struct s_room {
	char *name;
	int x;
	int y;
	int is_start;
	int is_end;
	struct s_room *next;
	struct s_room *all_next;    // for traversal
}	t_room;

typedef struct s_data {
	int ant_count;
	int got_start;
	int got_end;
	t_room *hash_table[4096];
	t_room *rooms;             // linked list of all rooms
}	t_data;

#endif
