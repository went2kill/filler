/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:11:19 by yrobotko          #+#    #+#             */
/*   Updated: 2017/08/24 18:14:42 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "stdlib.h"

typedef struct	s_fill
{
	char		my_sym;
	char		enemy_sym;
	int			mx;
	int			my;
	int			px;
	int			py;
	char		**map;
	int			**kmap;
	char		**piece;
	int			sym1;
	int			sym2;
	int			sym3;
	int			sym4;
	int			sym5;
	int			sym6;
	int			sym7;
	int			sym8;
	int			koef;
	int			ret_x;
	int			ret_y;
	int			count_touch;
}				t_fil;

void			help_func(t_fil *lst, int y, int x, int num);
int				calc_koef(t_fil *lst, int y, int x, int s_y);
void			get_num_pl(t_fil *lst, int fd);
void			save_map(t_fil *lst, int x, int y, int fd);
void			map_mall(t_fil *lst, int x, int y, int fd);
void			get_size_map(t_fil *lst, char *s);
void			get_size_piece(t_fil *lst, int fd);
void			save_piece(t_fil *lst, int x, int y, int fd);
void			piece_mall(t_fil *lst, int x, int y, int fd);
void			make_num_mp(t_fil *lst, int y, int en_sym, int num);
int				is_dots(int **str, int my, int mx);
void			make_kmap(t_fil *lst, int x, int y);
int				mall_kmap(t_fil *lst, int x, int y);
void			set_num(t_fil *lst);
int				can_place(t_fil *lst, int y, int x, int s_y);
int				search_place(t_fil *lst, int y, int x);
int				main(void);

#endif
