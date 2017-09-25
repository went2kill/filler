/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:23:16 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/24 18:05:41 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_size_piece(t_fil *lst, int fd)
{
	char	*s;

	get_next_line(fd, &s);
	lst->py = ft_atoi(&s[5]);
	lst->px = ft_atoi(&s[8]);
}

void		save_piece(t_fil *lst, int x, int y, int fd)
{
	char	*s;

	while (y < lst->py)
	{
		x = 0;
		get_next_line(fd, &s);
		while (x < lst->px)
		{
			lst->piece[y][x] = s[x];
			x++;
		}
		lst->piece[y][x] = '\0';
		y++;
	}
}

void		piece_mall(t_fil *lst, int x, int y, int fd)
{
	int		i;

	i = 0;
	lst->piece = (char**)malloc((y + 1) * sizeof(char*));
	while (i < y)
	{
		lst->piece[i] = (char*)malloc((x + 1) * sizeof(char));
		lst->piece[i][x] = '\0';
		i++;
	}
	lst->piece[i] = (char*)malloc(sizeof(char));
	lst->piece[i][0] = '\0';
	save_piece(lst, 0, 0, fd);
}

void		help_func(t_fil *lst, int y, int x, int num)
{
	int		**m;

	m = lst->kmap;
	if (y > 0 && m[y - 1][x] == -2)
		m[y - 1][x] = num + 1;
	if (x < lst->mx - 1 && m[y][x + 1] == -2)
		m[y][x + 1] = num + 1;
	if (y < lst->my - 1 && m[y + 1][x] == -2)
		m[y + 1][x] = num + 1;
	if (x > 0 && m[y][x - 1] == -2)
		m[y][x - 1] = num + 1;
	if (y > 0 && x > 0 && m[y - 1][x - 1] == -2)
		m[y - 1][x - 1] = num + 1;
	if (y > 0 && x < lst->mx - 1 && m[y - 1][x + 1] == -2)
		m[y - 1][x + 1] = num + 1;
	if (y < lst->my - 1 && x < lst->mx - 1 && m[y + 1][x + 1] == -2)
		m[y + 1][x + 1] = num + 1;
	if (y < lst->my - 1 && x > 0 && m[y + 1][x - 1] == -2)
		m[y + 1][x - 1] = num + 1;
}

void		make_num_mp(t_fil *lst, int y, int en_sym, int num)
{
	int		x;
	int		**m;

	m = lst->kmap;
	while (y < lst->my)
	{
		x = -1;
		while (++x < lst->mx)
		{
			if (m[y][x] == num)
				help_func(lst, y, x, num);
		}
		y++;
	}
}
