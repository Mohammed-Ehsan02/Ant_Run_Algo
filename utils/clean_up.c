#include "../includes/lem_in.h"

void	cleanup_input_lines(t_input_line *il)
{
	t_input_line *tmp;

	while (il)
	{
		tmp = il;
		il = il->next;
		free(tmp->line);
		free(tmp);
	}
}

void	cleanup_rooms(t_room *room)
{
	t_room *next_room;
	t_link *link;
	t_link *next_link;

	while (room)
	{
		next_room = room->all_next;
		free(room->name);
		link = room->links;
		while (link)
		{
			next_link = link->next;
			free(link);
			link = next_link;
		}
		free(room);
		room = next_room;
	}
}

void	cleanup_data(t_data *data)
{
	if (!data)
		return;
	cleanup_input_lines(data->input_lines);
	cleanup_rooms(data->rooms);
}

void clean_activate(t_data *data, t_vars *var, char *err)
{
	ft_putstr_fd(err, 2, 0);
	cleanup_data(data);
	free(var->line);
	free(var->tmp);
	exit(1);
}
