/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-20 15:48:53 by mradwan           #+#    #+#             */
/*   Updated: 2025-04-20 15:48:53 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_ant	*init_ants(int ant_count)
{
	t_ant	*ants;
	int		i;

	ants = (t_ant *)malloc(sizeof(t_ant) * ant_count);
	if (!ants)
		return (NULL);
	i = 0;
	while (i < ant_count)
	{
		ants[i].id = i + 1;
		ants[i].pos = -i - 1;
		i++;
	}
	return (ants);
}

int	advance_ants(t_ant *ants, int count, int path_len)
{
	int	i;
	int	done;

	done = 1;
	i = 0;
	while (i < count)
	{
		if (ants[i].pos < path_len)
		{
			ants[i].pos++;
			if (ants[i].pos < path_len)
				done = 0;
		}
		i++;
	}
	return (done);
}

void	simulate_ants(t_room **path, int path_len, int ant_count)
{
	t_ant	*ants;
	int		finished;

	ants = init_ants(ant_count);
	if (!ants)
		return ;
	finished = 0;
	while (!finished)
	{
		finished = advance_ants(ants, ant_count, path_len);
		print_turn(ants, ant_count, path, path_len);
	}
	free(ants);
}
