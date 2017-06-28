/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*int		expose_hook(t_window *win)
{
	calcul_coords(win);
	return (0);
}*/

void	redraw(t_window *window)
{
	ft_bzero(window->data, WIN_H * WIN_W * 4);
	calcul_coords(window);
}

void	zoom_inc(t_window *window)
{
	window->pad += 1;
	redraw(window);
}

void	zoom_dec(t_window *window)
{
	window->pad -= 1;
	redraw(window);
}

int		mouse_hook(int button, t_window *window)
{
	printf("Button %d\n", button);
	if (button == 4)
		zoom_inc(window);
	return (0);
}

int		key_hook(int keycode, t_window *window)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_clear_window(window->mlx, window->win);
		exit(0);
	}
	if (keycode == 69)
		zoom_inc(window);
	if (keycode == 78)
		zoom_dec(window);
	if (keycode == 123)
		move_l(window);
	if (keycode == 124)
		move_r(window);
	if (keycode == 126)
		move_u(window);
	if (keycode == 125)
		move_d(window);
	return (0);
}
