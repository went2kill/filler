/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:13:16 by yrobotko          #+#    #+#             */
/*   Updated: 2016/12/16 17:14:21 by yrobotko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islow(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
