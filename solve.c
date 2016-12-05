/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:30:53 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/02 15:01:17 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		search_solution(t_total *all, int nb, char *grid, int pos)
{
	if (nb == all->nb_piece)
		return (1);
	while (grid[pos])
	{
		if (check_fit(all->piece[nb], grid, pos) == 1)
		{
			if (search_solution(all, nb + 1, grid, 0) == 1)
				return (1);
			else
			{
				remove_piece(all->piece[nb], grid);
				return (search_solution(all, nb, grid, pos + 1));
			}
		}
		pos++;
	}
	return (0);
}

char	*solve(t_total *all)
{
	char	*grid;
	int		size;

	size = 2;
	grid = init_grid(size);
	while (search_solution(all, 0, grid, 0) == 0)
	{
		size++;
		free(grid);
		grid = init_grid(size);
	}
	return (grid);
}
