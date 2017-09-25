/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:35:09 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/24 17:40:43 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			can_place(t_fil *lst, int y, int x, int s_y)
{
	int		s_x;

	if ((y + lst->py) > lst->my)
		return (0);
	if ((x + lst->px) > lst->mx)
		return (0);
	lst->count_touch = 0;
	while (s_y < lst->py)
	{
		s_x = 0;
		while (s_x < lst->px)
		{
			if (lst->map[y + s_y][x + s_x] == lst->enemy_sym &&
					lst->piece[s_y][s_x] == '*')
				return (0);
			if (lst->map[y + s_y][x + s_x] == lst->my_sym &&
					lst->piece[s_y][s_x] == '*')
				lst->count_touch++;
			s_x++;
		}
		s_y++;
	}
	if (lst->count_touch == 1)
		return (1);
	return (0);
}

int			calc_koef(t_fil *lst, int y, int x, int s_y)
{
	int		s_x;
	int		koef;

	koef = 0;
	while (s_y < lst->py)
	{
		s_x = 0;
		while (s_x < lst->px)
		{
			if (lst->piece[s_y][s_x] == '*')
				koef += lst->kmap[y + s_y][x + s_x];
			s_x++;
		}
		s_y++;
	}
	return (koef);
}

int			search_place(t_fil *lst, int y, int x)
{
	int		fl;

	fl = 0;
	while (y < lst->my)
	{
		x = 0;
		while (x < lst->mx)
		{
			if (can_place(lst, y, x, 0))
			{
				fl = calc_koef(lst, y, x, 0);
				if (fl < lst->koef)
				{
					lst->koef = fl;
					lst->ret_x = x;
					lst->ret_y = y;
				}
			}
			x++;
		}
		y++;
	}
	return (fl);
}

int			main(void)
{
	t_fil	lst;
	int		fl;
	char	*s;

	fl = 1;
	ft_bzero(&lst, sizeof(lst));
	lst.koef = 9999;
	get_num_pl(&lst, 0);
	while (get_next_line(0, &s))
	{
		get_size_map(&lst, s);
		map_mall(&lst, lst.mx, lst.my, 0);
		get_size_piece(&lst, 0);
		piece_mall(&lst, lst.px, lst.py, 0);
		set_num(&lst);
		search_place(&lst, 0, 0);
		ft_printf("%d %d\n", lst.ret_y, lst.ret_x);
		lst.ret_x = 0;
		lst.ret_y = 0;
		lst.koef = 9999;
	}
	return (0);
}
