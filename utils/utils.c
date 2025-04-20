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
	arr = NULL;
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
	printf("\n=== END MAP DEBUG ===\n");
}