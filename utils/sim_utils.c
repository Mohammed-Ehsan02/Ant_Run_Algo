/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:33 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:33 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*get_path_by_idx(t_paths *paths, int idx)
{
	t_path	*curr;
	int		i;

	curr = paths->list;
	i = 0;
	while (curr && i < idx)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}

void	print_ant_move(int id, char *name, int *printed)
{
	if (*printed)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd('L', 1);
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('-', 1);
	ft_putstr_fd(name, 1, 0);
	*printed = 1;
}
