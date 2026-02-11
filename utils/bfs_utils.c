/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:33 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:33 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reset_bfs_flags(t_data *data)
{
	t_room	*room;

	room = data->rooms;
	while (room)
	{
		room->visited = 0;
		room->prev = NULL;
		room = room->all_next;
	}
}

void	reset_used_flags(t_data *data)
{
	t_room	*room;

	room = data->rooms;
	while (room)
	{
		room->used = 0;
		room = room->all_next;
	}
}

void	mark_path_used(t_room **path, int len)
{
	int	i;

	i = 1;
	while (i < len - 1)
	{
		path[i]->used = 1;
		i++;
	}
}
