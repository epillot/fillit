/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:00:52 by cbegne            #+#    #+#             */
/*   Updated: 2016/11/21 15:44:11 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char *av)
{
	char	*grid;
	int		i;
	int		fd;
	t_total	*all;

	i = -1;
	fd = open_file(av);
	if (!(all = read_file(fd)))
	{
		ft_putendl("error");
		return ;
	}
	close(fd);
	while (++i < all->nb_piece)
	{
		if (!(piece_valid(all->piece[i])))
		{
			ft_putendl("error");
			return ;
		}
	}
	grid = solve(all);
	free(all);
	ft_putstr(grid);
	free(grid);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file_name");
		return (0);
	}
	else
		fillit(av[1]);
}
