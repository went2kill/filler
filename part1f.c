/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:22:39 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/24 18:16:32 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_dots(int **str, int my, int mx)
{
	int		x;
	int		y;

	y = 0;
	while (y < my)
	{
		x = 0;
		while (x < mx)
		{
			if (str[y][x] == -2)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void		make_kmap(t_fil *lst, int x, int y)
{
	char	**map;
	int		**kmap;

	map = lst->map;
	kmap = lst->kmap;
	while (y < lst->my)
	{
		x = 0;
		while (x < lst->mx)
		{
			if (map[y][x] == lst->enemy_sym)
				kmap[y][x] = 0;
			else
				kmap[y][x] = -2;
			x++;
		}
		y++;
	}
}

int			mall_kmap(t_fil *lst, int x, int y)
{
	int		i;

	i = 0;
	lst->kmap = (int**)malloc((y) * sizeof(int*));
	while (i < y)
	{
		lst->kmap[i] = (int*)malloc((x) * sizeof(int));
		i++;
	}
	make_kmap(lst, 0, 0);
	return (0);
}

void		set_num(t_fil *lst)
{
	int		num;

	num = 0;
	mall_kmap(lst, lst->mx, lst->my);
	make_num_mp(lst, 0, 0, num);
	num++;
	while (is_dots(lst->kmap, lst->my, lst->mx))
	{
		make_num_mp(lst, 0, 0, num);
		num++;
	}
}
