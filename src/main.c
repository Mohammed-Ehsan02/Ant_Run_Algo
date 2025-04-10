#include "../includes/lem_in.h"

void	read_input(t_data *data, char **av)
{
	
	char *tmp = NULL;
	int ant_parsed = 0;
	char *line = NULL;
	
	int fd = open(av[1], O_RDONLY);
	if(fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((tmp = get_next_line(fd)))
	{
		line = ft_strtrim(tmp, "\n");
		// printf("Read line: %s\n", line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
			{
				if (!ft_strcmp(line, "##start"))
					data->got_start = 1;
				else if (!ft_strcmp(line, "##end"))
					data->got_end = 1;
			}
			free(line);
			free(tmp);
			continue ;
		}
		if (!ant_parsed)
		{
			if (parse_ants(line, data) < 0)
				return (free(tmp), free(line), exit(1));
			ant_parsed = 1;
		}
		// else if (parse_room(line, data) < 0)
		// 	break ; // transition to links or error
		free(line);
		free(tmp);
	}
}

int	parse_input(int ac, char **av, t_data *data)
{
    ft_bzero(data, sizeof(data));
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
	// run_simulation();
	return (0);
}
