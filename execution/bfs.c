#include "../includes/lem_in.h"

static t_qnode *create_queue_node(t_room *room)
{
	t_qnode *node = malloc(sizeof(t_qnode));
	if (!node)
		return (NULL);
	node->room = room;
	node->next = NULL;
	return (node);
}

static void enqueue(t_qnode **head, t_qnode **tail, t_room *room)
{
	t_qnode *node = create_queue_node(room);
	if (!node)
		return;
	if (!*head)
		*head = node;
	else
		(*tail)->next = node;
	*tail = node;
}

static t_room *dequeue(t_qnode **head)
{
	t_qnode *tmp;
	t_room *room;

	if (!*head)
		return (NULL);
	tmp = *head;
	room = tmp->room;
	*head = tmp->next;
	free(tmp);
	return (room);
}

static void free_queue(t_qnode *head)
{
	t_qnode *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	bfs_find_path(t_data *data)
{
	t_qnode *q_head;
	t_qnode *q_tail;
	t_room *curr;
	t_link *link;

	q_head = NULL;
	q_tail = NULL;
	enqueue(&q_head, &q_tail, data->start);
	data->start->visited = 1;
	while ((curr = dequeue(&q_head)))
	{
		if (curr == data->end)
			break;
		link = curr->links;
		while (link)
		{
			if (link->room->visited == 0)
			{
				link->room->visited = 1;
				link->room->prev = curr;
				enqueue(&q_head, &q_tail, link->room);
			}
			link = link->next;
		}
	}
	free_queue(q_head);
	if (data->end->prev)
		return (1);
	return (0);
}
