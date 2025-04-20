/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:52:59 by mradwan           #+#    #+#             */
/*   Updated: 2025/04/20 19:52:59 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	run_debug_tests(t_data *data, t_room **path, int path_len)
// {
// 	ft_putstr_fd("=== DEBUG ===\n", 1, 0);
// 	ft_putstr_fd("Ants: ", 1, 0);
// 	ft_putnbr_fd(data->ant_count, 1);
// 	ft_putchar_fd('\n', 1);
// 	print_path_reverse(data->end);
// 	print_path_forward(path, path_len);
// 	print_map_debug(data);
// 	ft_putstr_fd("=== END DEBUG ===\n", 1, 0);
// }

void	print_original_map(t_input_line *head)
{
	while (head)
	{
		ft_putstr_fd(head->line, 1, 0);
		ft_putchar_fd('\n', 1);
		head = head->next;
	}
	ft_putchar_fd('\n', 1);
}
