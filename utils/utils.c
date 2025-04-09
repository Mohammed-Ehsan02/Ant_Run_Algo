#include "../includes/lemin.h"

int	is_number(const char *str)
{
	int i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if(!(ft_isdigit(str[i])) && str[i] != '\n')
			return (0);	
		i++;
	}
	return (1);
}

unsigned int	hash(const char *s)
{
	unsigned int h = 0;
	while (*s)
		h = (h * 31) + *(s++);
	return (h % 4096);
}

int	parse_ants(char *line, t_data *data)
{
	if (!is_number(line))
		return (-1);
	data->ant_count = ft_atoi(line);
	return (0);
}