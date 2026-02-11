/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 15:48:31 by mradwan           #+#    #+#             */
/*   Updated: 2025-04-20 15:48:31 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	get_path_length(t_room *end)
{
	int	len;

	len = 0;
	while (end)
	{
		len++;
		end = end->prev;
	}
	return (len);
}

t_room	**build_path_array(t_room *end, int *len_out)
{
	int		len;
	t_room	**path;
	int		i;

	len = get_path_length(end);
	path = (t_room **)malloc(sizeof(t_room *) * len);
	if (!path)
		return (NULL);
	i = len - 1;
	while (end)
	{
		path[i] = end;
		end = end->prev;
		i--;
	}
	*len_out = len;
	return (path);
}

t_path	*create_path_node(t_room **rooms, int len)
{
	t_path	*node;

	node = malloc(sizeof(t_path));
	if (!node)
		return (NULL);
	node->rooms = rooms;
	node->len = len;
	node->ants = 0;
	node->next = NULL;
	return (node);
}

int	add_path_to_list(t_paths *paths, t_room **rooms, int len)
{
	t_path	*node;
	t_path	*last;

	node = create_path_node(rooms, len);
	if (!node)
		return (0);
	if (!paths->list)
		paths->list = node;
	else
	{
		last = paths->list;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	paths->count++;
	return (1);
}
