/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 15:48:53 by mradwan           #+#    #+#             */
/*   Updated: 2025-04-20 15:48:53 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_mant	*init_and_assign(t_paths *paths)
{
	t_mant	*ants;
	t_path	*p;
	int		i;
	int		pidx;

	ants = malloc(sizeof(t_mant) * paths->total_ants);
	if (!ants)
		return (NULL);
	i = 0;
	pidx = 0;
	p = paths->list;
	while (p)
	{
		while (p->ants > 0 && i < paths->total_ants)
		{
			ants[i].id = i + 1;
			ants[i].path_idx = pidx;
			ants[i].pos = 0;
			p->ants--;
			i++;
		}
		pidx++;
		p = p->next;
	}
	return (ants);
}

static int	try_move_ant(t_mant *ant, t_path *path, t_mant *all, int cnt)
{
	int		i;
	t_room	*target;

	if (ant->pos >= path->len - 1)
		return (0);
	target = path->rooms[ant->pos + 1];
	if (!target->is_end)
	{
		i = 0;
		while (i < cnt)
		{
			if (all[i].path_idx == ant->path_idx && all[i].pos == ant->pos + 1)
				return (0);
			i++;
		}
	}
	ant->pos++;
	return (1);
}

static int	do_one_turn(t_mant *ants, int cnt, t_paths *paths, int *printed)
{
	int		i;
	int		moved;
	t_path	*path;

	moved = 0;
	i = cnt - 1;
	while (i >= 0)
	{
		path = get_path_by_idx(paths, ants[i].path_idx);
		if (try_move_ant(&ants[i], path, ants, cnt))
		{
			print_ant_move(ants[i].id, path->rooms[ants[i].pos]->name, printed);
			moved = 1;
		}
		i--;
	}
	return (moved);
}

static int	all_done(t_mant *ants, int cnt, t_paths *paths)
{
	int		i;
	t_path	*path;

	i = 0;
	while (i < cnt)
	{
		path = get_path_by_idx(paths, ants[i].path_idx);
		if (ants[i].pos < path->len - 1)
			return (0);
		i++;
	}
	return (1);
}

void	simulate_multi(t_paths *paths)
{
	t_mant	*ants;
	int		printed;

	ants = init_and_assign(paths);
	if (!ants)
		return ;
	while (!all_done(ants, paths->total_ants, paths))
	{
		printed = 0;
		do_one_turn(ants, paths->total_ants, paths, &printed);
		if (printed)
			ft_putchar_fd('\n', 1);
	}
	free(ants);
}
