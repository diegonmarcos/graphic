/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibx_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:39:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 09:54:41 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef MYLIBX_DATA_H
# define MYLIBX_DATA_H

# include "mylibx.h"
# include <stdbool.h>

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

#endif

/* 
typedef struct m_colors
{
	int	topcolor;
	int	groundcolor;
	int	bottomcolor;
	int	backcolor;
	int	menucolor;	
}			t_colors;

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
	bool		b_lines;
	bool		b_dots;
	bool		b_pluslines;
	bool		b_geo;
	bool		b_stars;
	bool		b_shadow;
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
}				t_meta; */