/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:00:51 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:00:58 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_window *window)
{
	int x;
	int y;

	y = 0;
	while (window->map[y + 1])
	{
		x = 0;
		while (window->map[y + 1][x + 1])
		{
			ft_bresenham(window->map, x, y, window);
			x++;
		}
		y++;
	}
	x = 0;
	while (window->map[y][x])
	{
		if (window->map[y][x + 1] != NULL)
			ft_seg(window->map[y][x], window->map[y][x + 1], window);
		x++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->img, 0, 0);
}

void	ft_slow_increase(t_bresenham *bres, t_window *window)
{
	int i;
	int color;

	color = 0x00FFFF00;
	bres->cumul = bres->dx / 2;
	i = 1;
	while (i <= bres->dx)
	{
		bres->x += bres->xinc;
		bres->cumul += bres->dy;
		if (bres->cumul >= bres->dx)
		{
			bres->cumul -= bres->dx;
			bres->y += bres->yinc;
		}
		if (check_x(bres->x) && check_y(bres->y))
		{
			ft_memcpy(&window->data[(bres->x * 4) + (bres->y * window->size)], (const void *)&(color),
				(size_t)(sizeof(int)));
		}
		i++;
	}
}

void	ft_high_increase(t_bresenham *bres, t_window *window)
{
	int i;
	int color;

	color = 0x00FFFF00;
	bres->cumul = bres->dy / 2;
	i = 1;
	while (i <= bres->dy)
	{
		bres->y += bres->yinc;
		bres->cumul += bres->dx;
		if (bres->cumul >= bres->dy)
		{
			bres->cumul -= bres->dy;
			bres->x += bres->xinc;
		}
		if (check_x(bres->x) && check_y(bres->y))
		{
			ft_memcpy(&window->data[(bres->x * 4) + (bres->y * window->size)], (const void *)&(color),
				(size_t)(sizeof(int)));
		}
		i++;
	}
}

void	ft_draw_seg(t_bresenham *bres, t_window *window)
{
		if (bres->dx > bres->dy)
			ft_slow_increase(bres, window);
		else
			ft_high_increase(bres, window);
}

void	ft_seg(t_points *tab, t_points *tabnext, t_window *window)
{
	t_bresenham	*bres;

	bres = malloc(sizeof(t_bresenham));
	bres->x = tab->new_x;
	bres->y = tab->new_y;
	bres->dx = tabnext->new_x - tab->new_x;
	bres->dy = tabnext->new_y - tab->new_y;
	bres->xinc = (bres->dx > 0 ? 1 : -1);
	bres->yinc = (bres->dy > 0 ? 1 : -1);
	bres->dx = (bres->dx >= 0 ? bres->dx : -bres->dx);
	bres->dy = (bres->dy >= 0 ? bres->dy : -bres->dy);
	ft_draw_seg(bres, window);
	free(bres);
}
