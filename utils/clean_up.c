/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:56 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:56 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	cleanup_input_lines(t_input_line *il)
{
	t_input_line	*tmp;

	while (il)
	{
		tmp = il;
		il = il->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
	}
}

void	cleanup_rooms(t_room *room)
{
	t_room	*next_room;
	t_link	*link;
	t_link	*next_link;

	while (room)
	{
		next_room = room->all_next;
		if (room->name)
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
		return ;
	cleanup_input_lines(data->input_lines);
	cleanup_rooms(data->rooms);
	data->input_lines = NULL;
	data->rooms = NULL;
	data->start = NULL;
	data->end = NULL;
}

void	clean_activate(t_data *data, t_vars *var, char *err)
{
	ft_putstr_fd(err, 2, 0);
	if (var->line)
		free(var->line);
	if (var->tmp)
		free(var->tmp);
	cleanup_data(data);
	exit(1);
}

void	free_queue(t_qnode *head)
{
	t_qnode	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
