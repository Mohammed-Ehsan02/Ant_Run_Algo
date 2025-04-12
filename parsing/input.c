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

static void clean_activate(t_data *data, t_vars *var, char *err)
{
	ft_putstr_fd(err, 2, 0);
	cleanup_data(data);
	free(var->line);
	free(var->tmp);
	exit(1);
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

void	read_input(t_data *data, char **av)
{
	t_vars var;
	
	ft_bzero(&var, sizeof(t_vars));
	var.parsing_rooms = 1;
	var.fd = open(av[1], O_RDONLY);
	if(var.fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((var.tmp = get_next_line(var.fd)))
	{
		var.line = ft_strtrim(var.tmp, "\n");
		// printf("Read var.line: %s\n", var.line);
		if (var.line[0] == '#')
		{
			start_end(&var);
			continue;
		}
		checker_after_read(data, &var);
		free(var.line);
		free(var.tmp);
	}
	close(var.fd);
}