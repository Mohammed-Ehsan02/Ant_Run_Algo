#include "../includes/lem_in.h"

void	read_input(t_data *data, char **av)
{
	char *tmp = NULL;
	int ant_parsed = 0;
	char *line = NULL;
	t_vars var;
	int parsing_rooms = 1;
	
	var.is_start = 0;
	var.is_end = 0;
	var.fd = open(av[1], O_RDONLY);
	if(var.fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	while ((tmp = get_next_line(var.fd)))
	{
		line = ft_strtrim(tmp, "\n");
		// printf("Read line: %s\n", line);
		if (line[0] == '#')
		{
			if (line[1] == '#')
			{
				if (!ft_strcmp(line, "##start"))
					var.is_start = 1;
				else if (!ft_strcmp(line, "##end"))
					var.is_end = 1;
			}
			free(line);
			free(tmp);
			continue;
		}
		if (!ant_parsed)
		{
			if (parse_ants(line, data) < 0)
			{
				ft_putstr_fd("ERROR: Invalid ant count\n", 2, 0);
				free(line);
				free(tmp);
				exit(1);
			}
			ant_parsed = 1;
		}
		else if (parsing_rooms && ft_strchr(line, ' ')) // This is a room definition
		{
			if (parse_room(line, data, &var) < 0)
			{
				ft_putstr_fd("ERROR: Invalid room definition\n", 2, 0);
				free(line);
				free(tmp);
				exit(1);
			}
			var.is_start = 0;
			var.is_end = 0;
		}
		else if (ft_strchr(line, '-')) // This is a link definition
		{
			parsing_rooms = 0;
			if (parse_link(line, data) < 0)
			{
				ft_putstr_fd("ERROR: Invalid link definition\n", 2, 0);
				free(line);
				free(tmp);
				exit(1);
			}
		}
		free(line);
		free(tmp);
	}
	close(var.fd);
}

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
