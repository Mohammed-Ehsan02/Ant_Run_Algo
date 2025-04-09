#include "../includes/lemin.h"


void	read_input(t_data *data, char **av)
{
	
	char *line = NULL;
	int ant_parsed = 0;

	
	int fd = open(av[1], O_RDONLY);
	if(fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((line = get_next_line(fd)))
	{
		// printf("Read line: %s", line);
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
			continue ;
		}
		if (!ant_parsed)
		{
			if (parse_ants(line, data) < 0)
				return (free(line), exit(1));
			ant_parsed = 1;
		}
		// else if (parse_room(line, data) < 0)
		// 	break ; // transition to links or error
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

    ft_bzero(&data, sizeof(data));
	ft_bzero(data.hash_table, sizeof(data.hash_table));

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./lem_in <input_file>\n", 2, 0);
		return (1);
	}
	read_input(&data, av);

	return (0);
}