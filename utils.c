#include "lemin.h"

int	is_number(const char *str)
{
	int i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
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