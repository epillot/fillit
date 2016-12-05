/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coo_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:01:56 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/21 15:29:50 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		same_coo(t_point block1, t_point block2)
{
	if (block1.x == block2.x)
		return (1);
	if (block1.y == block2.y)
		return (1);
	return (0);
}

int		coo_close(t_point block1, t_point block2)
{
	if (block1.x == block2.x - 1 || block1.x == block2.x + 1)
		return (1);
	if (block1.y == block2.y - 1 || block1.y == block2.y + 1)
		return (1);
	return (0);
}

int		coo_valid(t_point block1, t_point block2)
{
	if (same_coo(block1, block2))
		if (coo_close(block1, block2))
			return (1);
	return (0);
}

int		two_coo_close(t_tetris piece)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (coo_valid(piece.block[i], piece.block[j])
						&& coo_valid(piece.block[i], piece.block[k])
						&& j != k && k != i && j != i)
					return (1);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		piece_valid(t_tetris piece)
{
	int i;
	int j;

	i = 0;
	if (two_coo_close(piece))
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4 && !coo_valid(piece.block[i], piece.block[j]))
				j++;
			if (j == 4)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
