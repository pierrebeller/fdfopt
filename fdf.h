/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../../minilibx_macos/mlx.h"
#include "../gnl/get_next_line.h"
#include <stdio.h>

#define ISO_CONST1 3
#define ISO_CONST2 2
#define	LENGTH 1280
#define WIDTH 800
#define ZOOM 5
#define ISO 1
#define PARA 0
#define BET_Z 2
#define ON 1
#define OFF 0

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				new_x;
	int				new_y;

}					t_points;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				cumul;
	int				x;
	int				y;
	int				xinc;
	int				yinc;

}					t_bresenham;

typedef	struct		s_window
{
	char			*path;
	void			*mlx;
	void			*win;
	int				opt;
	int				move_lr;
	int				move_ud;
	int				angle;
	int				rot;
	int				legend;
	t_points		***map;
	int				map_h;
	int				map_w;
}					t_window;

int			put_points(t_points ***tab);

void	calcul_coords(t_window *win);
void	calculate(t_window *win, t_points *point);
void	ft_bresenham(t_points ***tab, int x, int y, t_window *window);

void	draw_map(t_window *win);
void	ft_slow_increase(t_bresenham *bres, t_window *window);
void	ft_high_increase(t_bresenham *bres, t_window *window);
void	ft_draw_seg(t_bresenham *bres, t_window *window);
void	ft_seg(t_points *tab, t_points *tabnext, t_window *window);

int		expose_hook(t_window *win);
int		mouse_hook(int button, t_window *window);
int		key_hook(int keycode, t_window *window);

void	ft_do_fdf(t_window *win);

t_points	*ft_newpoint(char *data, int y, int index);
t_points	**ft_new_line(char *line, int y);
t_points	***ft_create_map(t_list *map, t_window *win);
t_points	***ft_fdf(t_window *win);

