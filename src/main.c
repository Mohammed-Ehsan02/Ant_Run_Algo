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

int main(int ac, char **av)
{
	t_data data;

	if (!parse_input(ac, av, &data))
	{
		ft_putstr_fd("ERROR\n", 2, 1);
		return (1);
	}
	print_map_debug(&data);
	cleanup_data(&data);
	return (0);
}
