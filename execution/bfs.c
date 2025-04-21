/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 15:48:12 by mradwan           #+#    #+#             */
/*   Updated: 2025-04-20 15:48:12 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_qnode	*create_queue_node(t_room *room)
{
	t_qnode	*node;

	node = malloc(sizeof(t_qnode));
	if (!node)
		return (NULL);
	node->room = room;
	node->next = NULL;
	return (node);
}

static void	enqueue(t_qnode **head, t_qnode **tail, t_room *room)
{
	t_qnode	*node;

	node = create_queue_node(room);
	if (!node)
		return ;
	if (!*head)
		*head = node;
	else
		(*tail)->next = node;
	*tail = node;
}

static t_room	*dequeue(t_qnode **head)
{
	t_qnode	*tmp;
	t_room	*room;

	if (!*head)
		return (NULL);
	tmp = *head;
	room = tmp->room;
	*head = tmp->next;
	free(tmp);
	return (room);
}

void	run_bfs_loop(t_qnode **q_head, t_qnode **q_tail, t_data *data)
{
	t_room	*curr;
	t_link	*link;
	t_room	*adj;

	curr = dequeue(q_head);
	while (curr)
	{
		if (curr == data->end)
			return ;
		link = curr->links;
		while (link)
		{
			adj = link->room;
			if (!adj->visited)
			{
				adj->visited = 1;
				adj->prev = curr;
				enqueue(q_head, q_tail, adj);
			}
			link = link->next;
		}
		curr = dequeue(q_head);
	}
}

int	bfs_find_path(t_data *data)
{
	t_qnode	*q_head;
	t_qnode	*q_tail;
	t_room	*start;

	start = data->start;
	q_head = NULL;
	q_tail = NULL;
	enqueue(&q_head, &q_tail, start);
	start->visited = 1;
	run_bfs_loop(&q_head, &q_tail, data);
	free_queue(q_head);
	return (data->end->prev != NULL);
}
