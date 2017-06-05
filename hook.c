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

/*int		expose_hook(t_window *win)
{
	calcul_coords(win);
	return (0);
}*/

int		mouse_hook(int button, t_window *window)
{
	int temp;

	temp = window->map_h;
	printf("Mouse event %d\n", button);
	return (0);
}

int		key_hook(int keycode, t_window *window)
{
	printf("Keyboard event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_clear_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}
