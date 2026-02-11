/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:33 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:33 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	calc_turns(t_path *path)
{
	return (path->len - 1 + path->ants);
}

t_path	*find_best_path(t_path *list)
{
	t_path	*best;
	t_path	*curr;
	int		min_turns;

	best = list;
	min_turns = calc_turns(list);
	curr = list->next;
	while (curr)
	{
		if (calc_turns(curr) < min_turns)
		{
			min_turns = calc_turns(curr);
			best = curr;
		}
		curr = curr->next;
	}
	return (best);
}

void	distribute_ants(t_paths *paths)
{
	int		remaining;
	t_path	*best;

	remaining = paths->total_ants;
	while (remaining > 0)
	{
		best = find_best_path(paths->list);
		best->ants++;
		remaining--;
	}
}

static void	swap_paths(t_path *a, t_path *b)
{
	t_room	**tmp_rooms;
	int		tmp_len;
	int		tmp_ants;

	tmp_rooms = a->rooms;
	tmp_len = a->len;
	tmp_ants = a->ants;
	a->rooms = b->rooms;
	a->len = b->len;
	a->ants = b->ants;
	b->rooms = tmp_rooms;
	b->len = tmp_len;
	b->ants = tmp_ants;
}

void	sort_paths_by_len(t_paths *paths)
{
	t_path	*i;
	t_path	*j;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = paths->list;
		while (i && i->next)
		{
			j = i->next;
			if (i->len > j->len)
			{
				swap_paths(i, j);
				swapped = 1;
			}
			i = i->next;
		}
	}
}
