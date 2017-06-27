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

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define ISO_CONST1 2
# define ISO_CONST2 2
# define WIN_W 2500
# define WIN_H 1600
# define ZOOM 5
# define ISO 1
# define PARA 0
# define BET_Z 2
# define ON 1
# define OFF 0
# define COLOR 0x00FFFF00

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
	char 			*data;
	void			*img;
	int				opt;
	int				size;
	int				endian;
	int				color;
	int				pad;
	int				pad_h;
	int				move_lr;
	int				move_ud;
	int				angle;
	int				rot;
	int				legend;
	t_points		***map;
	int				map_h;
	int				map_w;
	int				max_z;
	int				max_x;
	int				max_y;
}					t_window;

int					put_points(t_points ***tab);

void				calcul_coords(t_window *win);
void				calculate(t_window *win, t_points *point);
void				ft_bresenham(t_points ***tab, int x, int y, t_window *window);

void				draw_map(t_window *win);
void				ft_slow_increase(t_bresenham *bres, t_window *window);
void				ft_high_increase(t_bresenham *bres, t_window *window);
void				ft_draw_seg(t_bresenham *bres, t_window *window);
void				ft_seg(t_points *tab, t_points *tabnext, t_window *window);

int					expose_hook(t_window *win);
int					mouse_hook(int button, t_window *window);
int					key_hook(int keycode, t_window *window);

void				ft_do_fdf(t_window *win);

t_points			*ft_newpoint(char *data, int y, int index, t_window *win);
t_points			**ft_new_line(char *line, int y, t_window *win);
t_points			***ft_create_map(t_list *map, t_window *win);
t_points			***ft_fdf(t_window *win);

int					check_x(int x);
int					check_y(int y);
#endif
