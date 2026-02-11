/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:33 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:33 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_paths	*init_paths(int ant_count)
{
	t_paths	*paths;

	paths = malloc(sizeof(t_paths));
	if (!paths)
		return (NULL);
	paths->list = NULL;
	paths->count = 0;
	paths->total_ants = ant_count;
	return (paths);
}

static int	process_one_path(t_paths *paths, t_data *data)
{
	t_room	**path_arr;
	int		path_len;

	path_arr = build_path_array(data->end, &path_len);
	if (!path_arr)
		return (0);
	if (!add_path_to_list(paths, path_arr, path_len))
	{
		free(path_arr);
		return (0);
	}
	mark_path_used(path_arr, path_len);
	reset_bfs_flags(data);
	return (1);
}

t_paths	*find_all_paths(t_data *data)
{
	t_paths	*paths;

	paths = init_paths(data->ant_count);
	if (!paths)
		return (NULL);
	while (bfs_find_path(data))
	{
		if (!process_one_path(paths, data))
			break ;
	}
	reset_used_flags(data);
	return (paths);
}

void	free_path(t_path *path)
{
	if (!path)
		return ;
	if (path->rooms)
		free(path->rooms);
	free(path);
}

void	free_all_paths(t_paths *paths)
{
	t_path	*curr;
	t_path	*next;

	if (!paths)
		return ;
	curr = paths->list;
	while (curr)
	{
		next = curr->next;
		free_path(curr);
		curr = next;
	}
	free(paths);
}
