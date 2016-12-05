/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:01:41 by epillot           #+#    #+#             */
/*   Updated: 2016/11/21 15:33:00 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			convert_coo(t_tetris *piece)
{
	int			i;
	int			j;
	int			k;

	k = 0;
	i = piece->block[0].x;
	j = piece->block[0].y;
	while (k < 4)
	{
		piece->block[k].x -= i;
		piece->block[k].y -= j;
		k++;
	}
}

void			extract_coo(char *s, t_total *all, int k)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			all->piece[k].block[j].x = i % 5;
			all->piece[k].block[j].y = i / 5;
			j++;
		}
		i++;
	}
	convert_coo(&(all->piece[k]));
}

int				open_file(char *file)
{
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void			create_piece(t_total *all, int i, char *buf)
{
	all->nb_piece++;
	extract_coo(buf, all, i);
	all->piece[i].name = all->nb_piece + 64;
}

t_total			*read_file(int fd)
{
	int			ret;
	int			last_ret;
	char		*buf;
	int			i;
	t_total		*all;

	i = -1;
	last_ret = 21;
	if (!(all = ft_memalloc(sizeof(t_total))))
		exit(EXIT_FAILURE);
	if (!(buf = ft_strnew(21)))
		exit(EXIT_FAILURE);
	while ((ret = read(fd, buf, 21)) && ++i > -2)
	{
		last_ret = ret;
		if (ret < 20 && ret > 0)
			return (NULL);
		if (is_valid(buf))
			create_piece(all, i, buf);
		else
			return (NULL);
	}
	free(buf);
	return (last_ret == 21 ? NULL : all);
}
