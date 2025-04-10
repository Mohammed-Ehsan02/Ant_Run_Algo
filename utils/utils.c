#include "../includes/lem_in.h"

void free_split(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_number(const char *str)
{
	int i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if(!(ft_isdigit(str[i])))
			return (0);	
		i++;
	}
	return (1);
}

unsigned int	hash(const char *s)
{
	unsigned int h = 0;
	while (*s)
		h = (h * 31) + *(s++);
	return (h % 4096);
}

int	parse_ants(char *line, t_data *data)
{
	if (!is_number(line))
		return (-1);
	data->ant_count = ft_atoi(line);
	return (0);
}

int	parse_room(char *line, t_data *data, int is_start, int is_end)
{
	char	**split;
	t_room	*room;
	int		hash_index;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
	{
		free_split(split);
		return (-1);
	}

	// Validate coordinates
	if (!is_number(split[1]) || !is_number(split[2]))
	{
		free_split(split);
		return (-1);
	}

	// Check for duplicate room name
	hash_index = hash(split[0]);
	room = data->hash_table[hash_index];
	while (room)
	{
		if (!ft_strcmp(room->name, split[0]))
		{
			free_split(split);
			return (-1);
		}
		room = room->next;
	}

	// Create new room
	room = (t_room *)malloc(sizeof(t_room));
	if (!room)
	{
		free_split(split);
		return (-1);
	}

	room->name = ft_strdup(split[0]);
	room->x = ft_atoi(split[1]);
	room->y = ft_atoi(split[2]);
	room->is_start = is_start;
	room->is_end = is_end;
	room->visited = 0;
	room->links = NULL;
	room->prev = NULL;
	room->next = data->hash_table[hash_index];
	room->all_next = data->rooms;
	data->hash_table[hash_index] = room;
	data->rooms = room;

	if (is_start)
		data->start = room;
	if (is_end)
		data->end = room;

	free_split(split);
	return (0);
}

void	print_map_debug(t_data *data)
{
	t_room	*room;
	t_link	*link;

	printf("=== MAP DEBUG ===\n");
	printf("Ant count: %d\n", data->ant_count);
	printf("Start room: %s\n", data->start ? data->start->name : "Not set");
	printf("End room: %s\n", data->end ? data->end->name : "Not set");
	printf("\nRooms:\n");

	room = data->rooms;
	while (room)
	{
		printf("\nRoom: %s\n", room->name);
		printf("  Coordinates: (%d, %d)\n", room->x, room->y);
		printf("  Type: %s%s\n", 
			room->is_start ? "START " : "",
			room->is_end ? "END" : "");
		printf("  Links to: ");
		
		link = room->links;
		if (!link)
			printf("None");
		while (link)
		{
			printf("%s", link->room->name);
			if (link->next)
				printf(", ");
			link = link->next;
		}
		printf("\n");
		room = room->all_next;
	}
	printf("\n=== END DEBUG ===\n");
}