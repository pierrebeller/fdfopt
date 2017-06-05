/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_do_fdf(t_window *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, LENGTH, WIDTH, "fdf");
	//win->pad = 15;
	window->opt = ISO;
	//win->pad_h = 5;
	window->move_lr = 1;
	window->move_ud = 1;
	//win->draw_type = PUT;
	window->angle = 0;
	window->rot = BET_Z;
	window->legend = ON;
	window->map_w = 0;
	//win->img = mlx_new_image(win->init, WIN_W, WIN_H);
	//win->data = mlx_get_data_addr(win->img, &(win->color), &(win->size), &(win->endian));
	window->map = ft_fdf(window);
	calcul_coords(window);
	mlx_key_hook(window->win, key_hook, window);
	//mlx_mouse_hook(window->win, mouse_hook, window);
	//mlx_expose_hook(window->win, expose_hook, window);
	mlx_loop(window->mlx);
}
