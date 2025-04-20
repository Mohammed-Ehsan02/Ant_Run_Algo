#include "../includes/lem_in.h"

int parse_input(int ac, char **av, t_data *data)
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
	print_original_map(data->input_lines);
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
