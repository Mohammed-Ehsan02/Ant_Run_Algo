#include "lemin.h"

int	main(void)
{
	t_data	data;

    ft_bzero(&data, sizeof(data));
	ft_bzero(data.hash_table, sizeof(data.hash_table));

	return (0);
}