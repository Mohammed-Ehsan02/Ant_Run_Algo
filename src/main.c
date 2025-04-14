#include "../includes/lem_in.h"

int	parse_input(int ac, char **av, t_data *data)
{
	*data = (t_data){0};
	ft_bzero(data->hash_table, sizeof(data->hash_table));
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./lem_in <input_file>\n", 2, 0);
		exit(1);
	}
	read_input(data, av);
	return (1);
}

void	run_debug_tests(t_data *data, t_room **path, int path_len)
{
	ft_putstr_fd("=== DEBUG ===\n", 1, 0);
	ft_putstr_fd("Ants: ", 1, 0);
	ft_putnbr_fd(data->ant_count, 1);
	ft_putchar_fd('\n', 1);

	print_path_reverse(data->end);
	print_path_forward(path, path_len);
	print_map_debug(data);
	ft_putstr_fd("=== END DEBUG ===\n", 1, 0);
}

int	run_simulation(t_data *data)
{
	t_room	**path;
	int		path_len;

	if (!bfs_find_path(data))
	{
		ft_putstr_fd("ERROR: No path from start to end.\n", 2, 1);
		return (1);
	}
	path = build_path_array(data->end, &path_len);
	if (!path)
	{
		ft_putstr_fd("ERROR: Path allocation failed.\n", 2, 1);
		return (1);
	}
    // !!! DANGER: REMOVE BEFORE SUBMISSION !!!
	// run_debug_tests(data, path, path_len); 

	simulate_ants(path, path_len, data->ant_count);
	free(path);
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
