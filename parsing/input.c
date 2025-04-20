#include "../includes/lem_in.h"

static void start_end(t_vars *var)
{
	if (var->line[1] == '#')
	{
		if (!ft_strcmp(var->line, "##start"))
			var->is_start = 1;
		else if (!ft_strcmp(var->line, "##end"))
			var->is_end = 1;
	}
	free(var->line);
	free(var->tmp);
}

static void checker_after_read(t_data *data, t_vars *var)
{
	if (!var->ant_parsed)
	{
		if (parse_ants(var->line, data) < 0)
			clean_activate(data, var, "ERROR: Invalid ant count\n");
		var->ant_parsed = 1;
	}
	else if (var->parsing_rooms && ft_strchr(var->line, ' ')) // This is a room definition
	{
		if (parse_room(var->line, data, var) < 0)
			clean_activate(data, var, "ERROR: Invalid room definition\n");
		var->is_start = 0;
		var->is_end = 0;
	}
	else if (ft_strchr(var->line, '-')) // This is a link definition
	{
		var->parsing_rooms = 0;
		if (parse_link(var->line, data) < 0)
			clean_activate(data, var, "ERROR: Invalid link definition\n");
	}
}

void	append_input_line(t_data *data, char *line)
{
	t_input_line *node;
	t_input_line *tail;

	node = malloc(sizeof(t_input_line));
	if (!node)
		exit(1);
	node->line = ft_strdup(line);
	node->next = NULL;
	if (!data->input_lines)
		data->input_lines = node;
	else
	{
		tail = data->input_lines;
		while (tail->next)
			tail = tail->next;
		tail->next = node;
	}
}

void	handle_line_logic(t_data *data, t_vars *var)
{
	if (var->line[0] == '#')
	{
		start_end(var);
		return;
	}
	checker_after_read(data, var);
	free(var->line);
	free(var->tmp);
}


void	read_input(t_data *data, char **av)
{
	t_vars var;

	(void)av;
	ft_bzero(&var, sizeof(t_vars));
	var.parsing_rooms = 1;
	var.fd = 0;
	if (var.fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((var.tmp = get_next_line(var.fd)))
	{
		var.line = ft_strtrim(var.tmp, "\n");
		append_input_line(data, var.line);
		handle_line_logic(data, &var);
	}
	// close(var.fd);
}
