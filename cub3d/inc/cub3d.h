/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenet <gvenet@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:30:08 by gvenet            #+#    #+#             */
/*   Updated: 2021/03/01 14:01:31 by gvenet           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "../../libft/libft.h"
# define DR 0.01745329251
# define P2 1.57079632679
# define P3 4.71238898038
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_AR 124
# define KEY_AL 123

typedef enum	e_bool
{
	false,
	true,
}				t_bool;

typedef struct	s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
	int		c;
	char	**rgb;
	int		er;
	int		nb_color;
}				t_color;

typedef struct	s_walls
{
	float	ca;
	float	line_h;
	float	line_o;
	int		color;
	float	ty;
	float	ty_step;
	float	ty_off;
	float	tx;
	float	sh;
	t_color	floor;
	t_color	ceil;
}				t_walls;

typedef struct	s_bresenham_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}				t_bresenham_line;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_size;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct	s_win
{
	void	*win;
	int		x;
	int		y;
	char	**resolution;
	int		i;
	int		er;
}				t_win;

typedef struct	s_rays
{
	int		r_div;
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		dof_limit;
	float	a;
	float	x;
	float	y;
	float	xo;
	float	yo;
	float	h_tan;
	float	v_tan;
	float	h_dist;
	float	h_x;
	float	h_y;
	float	v_dist;
	float	v_x;
	float	v_y;
	float	dist;
	int		mv;
	int		mh;
	float	s_dist;
}				t_rays;

typedef struct	s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	a;
	float	fov;
	int		nb_cam;
	float	move_speed;
	float	rotate_speed;
}				t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		**matrix;
	int		**pars;
	t_win	w_map;
	float	b_size;
	t_img	img;
}				t_map;

typedef struct	s_coor
{
	float	x;
	float	y;
	float	d;
	int		id;
	t_bool	draw;
	float	dx;
	float	dy;
	float	sx0;
	float	sy0;
	float	sx1;
	float	sy1;
	float	a;
	float	px;
	float	py;
	float	dist;
	float	h_px;
	float	h_py;
	t_bool	h_draw;
	float	v_px;
	float	v_py;
	t_bool	v_draw;
	float	ca;
	float	line_h;
	float	line_o;
	float	ty_step;
	float	ty_off;
	float	ty;
	float	tx;
	float	color;
}				t_coor;

typedef struct	s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		l_size;
	int		endian;
	char	*path;
	int		w;
	int		h;
	int		s;
	int		count;
	float	a;
	float	f_min;
	float	f_max;
	t_coor	*tab;
	t_color	c;
}				t_texture;

typedef	struct	s_save
{
	t_bool		save;
	int			*addr;
}				t_save;

typedef struct	s_move
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			al;
	int			ar;
}				t_move;

typedef struct	s_data
{
	int			error;
	int			valid_line;
	void		*mlx;
	t_win		win;
	t_player	p;
	t_map		map;
	t_rays		r;
	t_img		img;
	t_walls		w;
	t_texture	n_tex;
	t_texture	s_tex;
	t_texture	w_tex;
	t_texture	e_tex;
	t_texture	s;
	t_save		save;
	t_move		mov;
}				t_data;

void			data_init(t_data *d, char *av);
void			render(t_data *d);
void			draw_minimap_background(t_data *d);
void			minimap_drawcase(t_map *map, int i, int j, int color);
void			draw_minimap(t_map *map);
void			draw_camera(t_map *map, t_player *p);
void			minimap(void *mlx, t_map *map, t_player *p, t_data *d);
void			display_map(int **m, int x, int y);
void			pixel_put(t_img *img, int x, int y, int color);
void			raycaster(t_data *d, t_rays *r, t_player *p, t_map *m);
void			draw_walls(t_data *d, t_rays *r, t_walls *w);
void			walls(t_data *d);
void			draw_walls_background(t_data *d, t_walls *w);
void			load_textures(t_data *d);
int				create_color(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
void			load_sprites(t_data *d);
void			sprite_minimap(t_texture *s, t_player *p);
void			draw_minimap_sprites(t_map *m, t_texture *s);
void			camera_errors(t_data *d, t_map *m);
void			parse_param(t_data *d, char *av);
void			parse_map(t_data *d, char *av);
int				is_map(char *line);
int				is_empty(char *line);
void			check_v_lines(t_data *d, t_rays *r, t_player *p, t_map *m);
void			check_h_lines(t_data *d, t_rays *r, t_player *p, t_map *m);
void			limits(t_rays *r, t_player *p, t_map *m);
void			leave(t_data *d);
void			flood_fill_check(t_data *d, int x, int y);
void			save_img_to_bmp(t_data *d);
int				red_cross(t_data *d);
void			create_bmp(const char *filename, t_data *d);
void			alloc_var_init(t_data *d);
void			colors_limits(t_color *c);
void			draw_line(t_img *img, t_data *d, \
				t_bresenham_line pts, int color);
void			check_sprite_screen_v(t_data *d, t_map *m, \
				t_texture *s, t_rays *r);
void			check_sprite_screen_h(t_data *d, t_map *m, \
				t_texture *s, t_rays *r);
void			check_sprite_dist(t_data *d, t_texture *s);
void			wrong_symbol_map(char *l, t_data *d, int x);
void			wrong_nb_colors(char *format, t_color *c, t_data *d);
void			alloc_var_test(t_data *d);
void			mapdup(t_data *d, t_map *m);
void			test_res(t_data *d);
void			check_line_map(char *line, t_data *d, int *cnt);

int				key_presse(int keycode, t_data *d);
int				key_release(int keycode, t_data *d);
int				move_player(t_data *d);
void			a_moves(t_data *d);
void			w_moves(t_data *d);
void			s_moves(t_data *d);
void			d_moves(t_data *d);
void			arrows_moves(t_data *d);

#endif
