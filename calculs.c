/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calcul_coords(t_window *window)
{
	int i;
	int j;

	j = 0;
	while (j < window->map_h)
	{
		i = 0;
		while (i < window->map_w)
			calculate(window, window->map[j][i++]);
		j++;
	}
	draw_map(window);
}

void	calculate(t_window *window, t_points *point)
{
	if (window->opt == ISO)
	{
		point->new_x = window->pad * ((point->x) - (point->y)) + WIN_W / 2;
		point->new_y = window->pad * ((point->x) + (point->y)) / 2 - window->pad_h * (point->z) + WIN_H / 4;
	}
	else if (window->opt == PARA)
	{
		point->new_x = point->x - (point->z) / 2 + WIN_W/2;
		point->new_y = point->y + point->z + WIN_H / 3;
	}
}

void	ft_bresenham(t_points ***tab, int x, int y, t_window *window)
{
	while (tab[y][x] != NULL)
		{
			if (tab[y][x + 1] != NULL)
			{
				ft_seg(tab[y][x], tab[y][x + 1], window);
			}
			if (tab[y + 1][x] != NULL)
				ft_seg(tab[y][x], tab[y + 1][x], window);
			x++;
		}
}
