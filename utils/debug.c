#include "../includes/lem_in.h"

void	print_path_reverse(t_room *end)
{
	ft_putstr_fd("Path (reversed): ", 1, 0);
	while (end)
	{
		ft_putstr_fd(end->name, 1, 0);
		if (end->prev)
			ft_putstr_fd(" <- ", 1, 0);
		end = end->prev;
	}
	ft_putchar_fd('\n', 1);
}

void	print_path_forward(t_room **path, int len)
{
	int	i;

	i = 0;
	ft_putstr_fd("Path (forward): ", 1, 0);
	while (i < len)
	{
		ft_putstr_fd(path[i]->name, 1, 0);
		if (i < len - 1)
			ft_putstr_fd(" -> ", 1, 0);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
