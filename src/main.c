/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:50 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:50 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	parse_input(int ac, char **av, t_data *data)
{
	*data = (t_data){0};
	(void)av;
	ft_bzero(data->hash_table, sizeof(data->hash_table));
	if (ac != 1)
	{
		ft_putstr_fd("Usage: ./lem_in < input_file\n", 2, 0);
		return (0);
	}
	read_input(data, NULL);
	return (1);
}

int	run_simulation(t_data *data)
{
	t_paths	*paths;

	paths = find_all_paths(data);
	if (!paths || paths->count == 0)
	{
		ft_putstr_fd("ERROR\n", 2, 1);
		free_all_paths(paths);
		return (1);
	}
	sort_paths_by_len(paths);
	distribute_ants(paths);
	print_original_map(data->input_lines);
	simulate_multi(paths);
	free_all_paths(paths);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!parse_input(ac, av, &data))
	{
		ft_putstr_fd("ERROR\n", 2, 1);
		return (1);
	}
	if (run_simulation(&data))
	{
		cleanup_data(&data);
		return (1);
	}
	cleanup_data(&data);
	return (0);
}
