/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5___control_keys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 11:02:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function handle some key press events
*/
void	control_keys1(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		halt_exit_program(meta);
	if (key == KEY_R)
	{
		map_ini(&meta->map, 0);
		meta->map.proportion = \
		meta->map.limits.axis[Z] / meta->map.limits.axis[X];
		if (meta->map.proportion > 0.5)
			meta->map.zdivisor = meta->map.proportion * 30;
		colorize(&meta->map, meta);
		map_pipeline(meta, FREE);
	}
	if (key == KEY_C)
	{
		meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
		meta->map.source.axis[Y] = WINY / 2;
	}
	if (key == KEY_P)
	{
		parallel(&meta->map);
		map_pipeline(meta, FREE);
	}
}

/* 
*	This function handle some key press events
*/
void	control_keys2(int key, t_meta *meta)
{
	if (key == KEY_D)
		meta->map.b_dots = !meta->map.b_dots;
	if (key == KEY_L)
		meta->map.b_lines = !meta->map.b_lines;
	if (key == KEY_X)
		meta->map.b_pluslines = !meta->map.b_pluslines;
	if (key == KEY_G)
		meta->map.b_geo = !meta->map.b_geo;
	if (key == KEY_S)
		meta->map.b_stars = !meta->map.b_stars;
	if (key == KEY_H)
		meta->map.b_shadow = !meta->map.b_shadow;
	if (key == KEY_F)
		map_pipeline(meta, FIT);
	if (key == KEY_CMD)
		meta->keys.b_keyctrl = 1;
}

/* 
*	This function handle some key press events
*/
void	control_keys3(int key, t_meta *meta)
{
	if (key == KEY_B)
	{
		if (meta->keys.b_keyctrl)
			meta->map.brange -= 0.0001;
		else
			meta->map.brange += 0.0001;
	}
	if (key == KEY_SUM || key == KEY_SUM2)
	{
		if (meta->keys.b_keyctrl)
			meta->map.scale = meta->map.scale * 1.5;
		if (meta->map.zdivisor > 1)
			meta->map.zdivisor -= 0.5;
	}
	if (key == KEY_RES || key == KEY_RES2)
	{
		if (meta->keys.b_keyctrl)
			meta->map.scale = meta->map.scale / 1.5;
		meta->map.zdivisor += 0.5;
	}
	if (key == KEY_I)
	{
		isometric(&meta->map);
		map_pipeline(meta, FREE);
	}
}

/* 
*	This function add grades to the control structure depends the key pressed
*/
void	angle_control(int key, t_meta *meta)
{
	int	ang;

	ang = 1;
	if (meta->keys.b_keyctrl)
		ang = 90;
	if (key == KEY_DOWN)
		angle(&meta->map.ang[X], ang);
	if (key == KEY_UP)
		angle(&meta->map.ang[X], -ang);
	if (key == KEY_LEFT)
		angle(&meta->map.ang[Y], ang);
	if (key == KEY_RIGHT)
		angle(&meta->map.ang[Y], -ang);
	if (key == KEY_Q)
		angle(&meta->map.ang[Z], ang);
	if (key == KEY_W)
		angle(&meta->map.ang[Z], -ang);
}

/* 
*	This function handle the colorscheme dependig the key pressed
*/
void	control_colorscheme(int key, t_map *map, t_meta *meta)
{
	map->colors.backcolor = CARBON;
	map->colors.bottomcolor = AZUL;
	map->colors.topcolor = BRICK_RED;
	map->colors.groundcolor = SAFFRON;
	if (key == KEY_2)
	{
		map->colors.backcolor = WHITE;
		map->colors.bottomcolor = CARBON;
		map->colors.topcolor = CARBON;
		map->colors.groundcolor = CARBON;
	}
	if (key == KEY_3)
	{
		map->colors.bottomcolor = WHITE;
		map->colors.topcolor = WHITE;
		map->colors.groundcolor = WHITE;
	}
	if (key == KEY_4)
	{
		map->colors.bottomcolor = SUPERAZUL;
		map->colors.topcolor = ROJO;
		map->colors.groundcolor = VERDE;
	}
	colorize(map, meta);
}
