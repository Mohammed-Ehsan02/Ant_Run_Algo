#include "../includes/lem_in.h"

static void	print_turn(t_ant *ants, int total, t_room **path, int path_len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (i < total)
	{
		if (ants[i].pos >= 0 && ants[i].pos < path_len)
		{
			if (printed)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd('L', 1);
			ft_putnbr_fd(ants[i].id, 1);
			ft_putchar_fd('-', 1);
			ft_putstr_fd(path[ants[i].pos]->name, 1, 0);
			printed = 1;
		}
		i++;
	}
	if (printed)
		ft_putchar_fd('\n', 1);
}

void	simulate_ants(t_room **path, int path_len, int ant_count)
{
	t_ant	*ants;
	int		finished;
	int		i;

	ants = (t_ant *)malloc(sizeof(t_ant) * ant_count);
	if (!ants)
		return;
	i = 0;
	while (i < ant_count)
	{
		ants[i].id = i + 1;
		ants[i].pos = -i - 1; // offset each ant to enter one-by-one
		i++;
	}
	finished = 0;
	while (!finished)
	{
		finished = 1;
		i = 0;
		while (i < ant_count)
		{
			if (ants[i].pos < path_len)
			{
				ants[i].pos++;
				if (ants[i].pos < path_len)
					finished = 0;
			}
			i++;
		}
		print_turn(ants, ant_count, path, path_len);
	}
	free(ants);
}
