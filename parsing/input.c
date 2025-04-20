/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:42 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:42 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	start_end(t_vars *var)
{
	if (var->line[1] == '#')
	{
		if (!ft_strcmp(var->line, "##start"))
		{
			var->start_found = 1;
			var->is_start = 1;
		}
		else if (!ft_strcmp(var->line, "##end"))
		{
			var->end_found = 1;
			var->is_end = 1;
		}
	}
}

static void	checker_after_read(t_data *data, t_vars *var)
{
	if (!var->ant_parsed)
	{
		if (parse_ants(var->line, data) < 0)
			clean_activate(data, var, "ERROR: Invalid ant count\n");
		var->ant_parsed = 1;
	}
	else if (var->parsing_rooms && ft_strchr(var->line, ' '))
	{
		if (parse_room(var->line, data, var) < 0)
			clean_activate(data, var, "ERROR: Invalid room definition\n");
		var->is_start = 0;
		var->is_end = 0;
	}
	else if (ft_strchr(var->line, '-'))
	{
		var->parsing_rooms = 0;
		if (parse_link(var->line, data) < 0)
			clean_activate(data, var, "ERROR: Invalid link definition\n");
	}
}

void	append_input_line(t_data *data, char *line)
{
	t_input_line	*node;
	t_input_line	*tail;

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
		return ;
	}
	checker_after_read(data, var);
}

void	read_input(t_data *data, char **av)
{
	t_vars	var;

	(void)av;
	ft_bzero(&var, sizeof(t_vars));
	var.parsing_rooms = 1;
	var.tmp = get_next_line(var.fd);
	while ((var.tmp))
	{
		var.line = ft_strtrim(var.tmp, "\n");
		handle_line_logic(data, &var);
		append_input_line(data, var.line);
		free(var.line);
		free(var.tmp);
		var.line = NULL;
		var.tmp = NULL;
		var.tmp = get_next_line(var.fd);
	}
	if (!var.ant_parsed)
		clean_activate(data, &var, "ERROR: No ants specified\n");
	if (!var.start_found || !var.end_found)
		clean_activate(data, &var, "ERROR: No start or end room specified\n");
}
