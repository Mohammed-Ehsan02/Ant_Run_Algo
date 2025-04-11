#include "../includes/lem_in.h"

static int link_splitter(t_vars *var, char *line, t_data *data)
{
	var->split = ft_split(line, '-');
	if (!var->split || !var->split[0] || !var->split[1] || var->split[2])
	{
		free_split(var->split);
		return (-1);
	}
	var->hash_index = hash(var->split[0]);
	var->room1 = data->hash_table[var->hash_index];
	while (var->room1 && ft_strcmp(var->room1->name, var->split[0]))
		var->room1 = var->room1->next;
	var->hash_index = hash(var->split[1]);
	var->room2 = data->hash_table[var->hash_index];
	while (var->room2 && ft_strcmp(var->room2->name, var->split[1]))
		var->room2 = var->room2->next;
	if (!var->room1 || !var->room2)
	{
		free_split(var->split);
		return (-1);
	}
	return (0);
}

static int create_links(t_vars *var)
{
	t_link *new_link;

	new_link = (t_link *)malloc(sizeof(t_link));
	if (!new_link)
	{
		free_split(var->split);
		return (-1);
	}
	new_link->room = var->room2;
	new_link->next = var->room1->links;
	var->room1->links = new_link;
	new_link = (t_link *)malloc(sizeof(t_link));
	if (!new_link)
	{
		free(var->room1->links);
		var->room1->links = NULL;
		free_split(var->split);
		return (-1);
	}
	new_link->room = var->room1;
	new_link->next = var->room2->links;
	var->room2->links = new_link;
	return (0);
}

int	parse_link(char *line, t_data *data)
{
	t_vars var;

	ft_bzero(&var, sizeof(t_vars));
	if (link_splitter(&var, line, data) < 0)
		return (-1);
	if (create_links(&var) < 0)
		return (-1);
	free_split(var.split);
	return (0);
}