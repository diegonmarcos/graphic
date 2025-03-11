/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:40:13 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0. HEADERS															*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 0.1 C Library													 */
/* ***************************************************************** */
# include <math.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <error.h>
# include <stdbool.h>
# include <time.h>

/* ***************************************************************** */
/* 0.2 Program Headers												 */
/* ***************************************************************** */
# include "fdf_data.h"
# include "fdf_defines.h"
# include "fdf_defines_keys.h"
# include "fdf_defines_colors.h"

/* ***************************************************************** */
/* 0.3 Dependencies Headers											 */
/* ***************************************************************** */
/* ************************************************************* */
/* ************************************************************* */
//# include "../libs/minilibx/minilibx_linux/mlx.h"
# include "../libs/mylibc/inc/mylibc.h"
# include "../libs/mylibc/inc/mylibc_data.h"
# include "../libs/mylibc/inc/mylibc_defines.h"
# include "../libs/mylibx/inc/mylibx.h"
# include "../libs/mylibx/inc/mylibx_data.h"

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0. MYLIBX															*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 0.1 Draw Frame/Line												*/
/* ***************************************************************** */
void	mydrawframe(t_meta *meta, t_point *wire);
void	mydrawframe_row_lines(t_point *point, t_meta *meta, \
			int density, int line);
int		mydrawline(t_meta *meta, t_point start, t_point end);
int		myputpixel_check(t_meta *meta, t_point pixel);
void	myputpixel(char *buffer, int endian, int color, int alpha);

/* ***************************************************************** */
/* 0.1 Draw Circle													 */
/* ***************************************************************** */
void	mydrawcircle(t_meta *meta, t_point *map_points);
void	draw_dot(t_meta *meta, t_point point, int radius);
void	dot_util(t_meta *meta, t_point pixel, t_point point, int coord);

/* ***************************************************************** */
/* 3.4 Draw Utils													 */
/* ***************************************************************** */
int		valid_pixel(t_point pixel);
int		limits(t_point *points, int len);
int		color_convert_depth(t_meta *meta, int color);

/* ***************************************************************** */
/* 3.4 Draw Utils/Colorize											 */
/* ***************************************************************** */
void	load_color(int max, int min, t_point *point, t_colors	colors);
void	colorize(t_map *map);
int		gradient(int startcolor, int endcolor, int len, int pix);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 1. MAP LOAD															*/
/*#####################################################################	*/
void	map_load(t_map *map, char *path);
/* ***************************************************************** */
/* 1.1 Map Load														 */
/* ***************************************************************** */
void	map_ini(t_map *map, int total);
void	map_ini_colors(t_map *map);
void	map_size(t_map *map);
void	copy_map(t_point *src, t_point *dst, int len);
void	map_checker(char c);

/* ***************************************************************** */
/* 1.1 Get points													 */
/* ***************************************************************** */
void	map_get_points(t_map *map);
int		load_points(char *line, t_map *map, int numline);
int		valid_point(char *value);
int		has_hexcolors(char *line);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
int		map_pipeline(t_meta *meta, int fit);

/*#####################################################################	*/
/* 2. MAP TRANSFORMATION												*/
/*#####################################################################	*/
void	map_transformation(t_meta *meta, t_point *map_points);

/* ***************************************************************** */
/* 2. Map Transformation											 */
/* ***************************************************************** */
void	z_division(t_point *map_points, float divisor, int len);
void	bending(t_point *points, int len, float range);
void	rotate_x(t_point *points, t_point *projection, float ang, int len);
void	rotate_y(t_point *points, t_point *projection, float ang, int len);
void	rotate_z(t_point *points, t_point *projection, float ang, int len);
void	ortogonal_projection(t_point *points, t_point *projection, int len);
t_point	matrix3_multp(float matrix[3][3], t_point point);
void	scale(t_point *points, int scale, int len);
void	traslate(t_point *points, t_point move, int len);
void	go_polar(t_map *map);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 3. MAP RENDER															*/
/*#####################################################################	*/
void	map_render(t_meta *meta, t_point *map_points);

/* ***************************************************************** */
/* 3.1 Render											 */
/* ***************************************************************** */
void	render_background(t_meta *meta, int backcolor, int menucolor);
void	fit_to_scale(t_meta *meta, t_point *map_points, int fit);

/* ***************************************************************** */
/* 3.2 Menu															 */
/* ***************************************************************** */
void	render_menu(t_meta *meta);
void	draw_info(t_meta *meta);
void	draw_controls(t_meta *meta);
void	draw_mapinfo(t_meta *meta);
void	draw_colorscheme(t_meta *meta);

/* ***************************************************************** */
/* 3.3 Views Features/Bonus											 */
/* ***************************************************************** */
void	isometric(t_map *map);
void	parallel(t_map *map);
void	spherize(t_map *map, t_point *points);
void	render_stars(t_meta *meta);
void	shadow(t_point *points, int len);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 4. SYSTEM															*/
/*#####################################################################	*/
/* ***************************************************************** */
/* 4.1 System														 */
/* ***************************************************************** */
void	system_init(t_meta *meta);
void	system_init_keys(t_meta *meta);


/* ***************************************************************** */
/* 4.2 Control Keys													 */
/* ***************************************************************** */
//# include "keycodes.h"
int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	control_keys1(int key, t_meta *meta);
void	control_keys2(int key, t_meta *meta);
void	control_keys3(int key, t_meta *meta);

/* ***************************************************************** */
/* 4.3 Control Mouse												 */
/* ***************************************************************** */
int		mouse_move(int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

/* ***************************************************************** */
/* 4.4 Control Utils												 */
/* ***************************************************************** */
void	control_colorscheme(int key, t_map *map);
void	angle_control(int key, t_meta *meta);
void	angle(float *ang, float value);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 4. UTILS															*/
/*#####################################################################	*/
int		halt_exit_program(void *param);
void	terminate(char *s);
void	terminate1(char *s, t_meta *meta);
void	print_nbr(t_meta *meta, int x, int y, int nbr);
void	print_str(t_meta *meta, int x, int y, char *str);

#endif
