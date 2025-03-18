/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:39:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 08:05:54 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

# include "fdf.h"
# include "../libs/mylibx/inc/mylibx_data.h"

/* ***************************************************************** */
/* 1.1 Data Structure												 */
/* ***************************************************************** */
/* typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	bool	paint;
	float	polar[2];
}			t_point; */

typedef struct m_colors
{
	int	topcolor;
	int	groundcolor;
	int	bottomcolor;
	int	backcolor;
	int	menucolor;	
}		t_colors;

typedef struct s_bitmap
{
	void	*img;
	char	*buffer;
	int		bitxpixel;
	int		lines;
	int		endian;
}			t_bitmap;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_keys
{
	bool	b_mouse_l;
	bool	b_mouse_r;
	bool	b_keyctrl;
	t_point	last_click_l;
	t_point	last_click_r;
}			t_keys;

typedef struct m_map
{
	t_point		*points;
	t_point		limits;
	t_point		source;
	t_colors	colors;
	char		*memory;
	char		**lines;
	int			zmin;
	float		ang[3];
	float		zdivisor;
	float		scale;
	int			len;
	float		brange;
	int			renders;
	int			fit;
	bool		b_lines;
	bool		b_dots;
	bool		b_pluslines;
	bool		b_geo;
	bool		b_stars;
	bool		b_shadow;
	bool		b_auto_rotate;
	bool		b_menu;
	double		performance;
	float		proportion;
	float		radius;
}				t_map;

typedef struct s_meta
{
	t_vars		vars;
	t_bitmap	bitmap;
	t_map		map;
	t_keys		keys;
}				t_meta;

typedef struct s_xpm_image
{
	char	*xpm_path;
	void	*xpm_ptr;
}			t_xpm_image;

typedef struct s_xpm
{
	t_vars		vars;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			column;
	int			line;
	t_xpm_image	*xpm1;
	t_xpm_image	*xpm2;
	char		*xpm_path;
	char		*xpm_path2;
	void		*xpm_ptr;
	void		*xpm_ptr2;
	int			image_width_x;
	int			image_height_y;
	int			image_pos_x;
	int			image_pos_y;
	void		*black_img;
	t_bitmap	bitmap;
	int			bpp;
	int			sl;
	int			en;
	char		*black_ptr;
	int			frame_count;
}			t_xpm;

#endif
