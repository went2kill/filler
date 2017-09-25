/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:27:20 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/24 18:09:59 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_num_pl(t_fil *lst, int fd)
{
	char	*s;

	get_next_line(fd, &s);
	lst->my_sym = 'O';
	lst->enemy_sym = 'O';
	if (s[10] == '1')
		lst->enemy_sym = 'X';
	if (s[10] == '2')
		lst->my_sym = 'X';
}

void		save_map(t_fil *lst, int x, int y, int fd)
{
	char	*s;

	get_next_line(fd, &s);
	while (y < lst->my)
	{
		x = 4;
		get_next_line(fd, &s);
		while (x < lst->mx + 4)
		{
			lst->map[y][x - 4] = s[x];
			x++;
		}
		lst->map[y][x - 4] = '\0';
		y++;
	}
}

void		map_mall(t_fil *lst, int x, int y, int fd)
{
	int		i;

	i = 0;
	lst->map = (char**)malloc((y + 1) * sizeof(char*));
	while (i < y)
	{
		lst->map[i] = (char*)malloc((x + 1) * sizeof(char));
		lst->map[i][x] = '\0';
		i++;
	}
	lst->map[i] = (char*)malloc(sizeof(char));
	lst->map[i][0] = '\0';
	save_map(lst, 0, 0, fd);
}

void		get_size_map(t_fil *lst, char *s)
{
	lst->my = ft_atoi(&s[7]);
	lst->mx = ft_atoi(&s[11]);
	lst->sym1 = -3;
	lst->sym2 = -3;
	lst->sym3 = -3;
	lst->sym4 = -3;
}
