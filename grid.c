/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:25:52 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/02 15:11:36 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*init_grid(int size)
{
	int		i;
	char	*grid;

	i = 0;
	if (!(grid = ft_strnew((size + 1) * size)))
		exit(EXIT_FAILURE);
	while (i < ((size + 1) * size))
	{
		if ((i + 1) % (size + 1) != 0)
			grid[i] = '.';
		else
			grid[i] = '\n';
		i++;
	}
	return (grid);
}

int		check_fit(t_tetris piece, char *grid, int pos)
{
	int	pos2;
	int	k;
	int	size;

	size = 0;
	while (grid[size] != '\n')
		size++;
	k = 0;
	while (k < 4)
	{
		pos2 = (piece.block[k].x + (size + 1) * piece.block[k].y) + pos;
		if (grid[pos2] != '.' || pos2 >= size * (size + 1) \
				|| (pos2 + 1) % (size + 1) == 0)
			return (0);
		k++;
	}
	k = 0;
	while (k < 4)
	{
		pos2 = (piece.block[k].x + (size + 1) * piece.block[k].y) + pos;
		grid[pos2] = piece.name;
		k++;
	}
	return (1);
}

void	remove_piece(t_tetris piece, char *grid)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (grid[i] && k < 4)
	{
		if (grid[i] == piece.name)
		{
			grid[i] = '.';
			k++;
		}
		i++;
	}
}
