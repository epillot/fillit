/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epillot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:56:43 by epillot           #+#    #+#             */
/*   Updated: 2016/11/21 12:10:05 by epillot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetris
{
	char	name;
	t_point	block[4];
}				t_tetris;

typedef struct	s_total
{
	int			nb_piece;
	t_tetris	piece[26];
}				t_total;

char			*init_grid(int size);
void			convert_coo(t_tetris *piece);
void			extract_coo(char *s, t_total *all, int k);
int				open_file(char *file);
t_total			*read_file(int fd);
void			create_piece(t_total *all, int i, char *buf);
int				is_valid(char *buf);
int				check_fit(t_tetris piece, char *grid, int pos);
void			remove_piece(t_tetris piece, char *grid);
int				search_solution(t_total *all, int nb, char *grid, int pos);
char			*solve(t_total *all);
int				same_coo(t_point block1, t_point block2);
int				coo_close(t_point block1, t_point block2);
int				coo_valid(t_point block1, t_point block2);
int				piece_valid(t_tetris piece);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *str);
void			ft_putstr(char *str);
void			ft_putendl(char const *s);
void			ft_putchar(char c);

#endif
