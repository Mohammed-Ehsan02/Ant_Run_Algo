/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:47 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:47 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

unsigned int	hash(const char *s)
{
	unsigned int	h;

	h = 0;
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

static int	room_splitter(t_vars *var, char *line)
{
	var->hash_index = 0;
	var->split = ft_split(line, ' ');
	if (!var->split || !var->split[0] || !var->split[1]
		|| !var->split[2] || var->split[3])
	{
		free_split(var->split);
		return (-1);
	}
	if (!is_number(var->split[1]) || !is_number(var->split[2]))
	{
		free_split(var->split);
		return (-1);
	}
	return (0);
}

static int	room_initializer(t_data *data, t_vars *var, t_room **room)
{
	*room = (t_room *)malloc(sizeof(t_room));
	if (!*room)
		return (-1);
	(*room)->name = ft_strdup(var->split[0]);
	if (!(*room)->name)
	{
		free(*room);
		return (-1);
	}
	(*room)->x = ft_atoi(var->split[1]);
	(*room)->y = ft_atoi(var->split[2]);
	(*room)->is_start = var->is_start;
	(*room)->is_end = var->is_end;
	(*room)->visited = 0;
	(*room)->links = NULL;
	(*room)->prev = NULL;
	(*room)->next = data->hash_table[var->hash_index];
	(*room)->all_next = data->rooms;
	data->hash_table[var->hash_index] = *room;
	data->rooms = *room;
	if (var->is_start)
		data->start = *room;
	if (var->is_end)
		data->end = *room;
	return (0);
}

int	parse_room(char *line, t_data *data, t_vars *var)
{
	t_room	*room;
	t_room	*existing_room;

	if (room_splitter(var, line) < 0)
		return (-1);
	var->hash_index = hash(var->split[0]);
	existing_room = data->hash_table[var->hash_index];
	while (existing_room)
	{
		if (!ft_strcmp(existing_room->name, var->split[0]))
			return (free_split(var->split), -1);
		existing_room = existing_room->next;
	}
	if (room_initializer(data, var, &room) < 0)
	{
		free_split(var->split);
		var->split = NULL;
		return (-1);
	}
	free_split(var->split);
	var->split = NULL;
	return (0);
}
