/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___ckeys1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 07:49:42 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
* #MENU
* KEY_M will show/hide the menu
* KEY_ESC will halt the program
* KEY_CMD will change the behavior of the keys
* KEY_A will reset the map to the original state
* KEY_F will fit the map to the window
* KEY_C will center the map
*
* #PROJECTIONS VIEWS
* KEY_P will apply the parallel projection X
* KEY_O will apply the parallel projection Y
* KEY_I will apply the isometric projection
* KEY_B will aplying bending to the map
* KEY_G will apply the geo transformation
*
* #SHOW HIDE
* KEY_D will show/hide the dots
* KEY_L will show/hide the lines
* KEY_H will show/hide the shadow
* KEY_S will show/hide the stars
* 
* #ZOOM (ANGLES MOVE)
* KEY_SUM will zoom in
* KEY_RES will zoom out
* KEY_Q will change the angle of the map for the x axis
* KEY_W will change the angle of the map for the y axis
*
* #COLOR SCHEME
* KEY_1 will change the color scheme to the default
* KEY_2 will change the color scheme to the second
* KEY_3 will change the color scheme to the third
* KEY_4 will change the color scheme to the fourth
*
* # AUTO ROTATION
* KEY_E will start/stop the auto rotation 1
* KEY_R will start/stop the auto rotation 2
* KEY_T will start/stop the auto rotation 3
* KEY_Y will start/stop the auto rotation 4
*/
void	control_keys_menu(int key, t_meta *meta)
{
	if (key == KEY_A)
	{
		var_init_map0(&meta->map, 0);
		meta->map.proportion = \
		meta->map.limits.axis[Z] / meta->map.limits.axis[X];
		if (meta->map.proportion > 0.5)
			meta->map.zdivisor = meta->map.proportion * 30;
		colorize(&meta->map, meta);
		map_pipeline(meta, FREE);
	}
	if (key == KEY_F)
		map_pipeline(meta, FIT);
	if (key == KEY_C)
	{
		meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
		meta->map.source.axis[Y] = WINY / 2;
	}
	if (key == KEY_M)
		meta->map.b_menu = !meta->map.b_menu;
	if (key == KEY_CMD)
		meta->keys.b_keyctrl = 1;
	if (key == KEY_ESC)
		terminate(2, 0, "0", meta);
}

/* 
*	This function handle some key press events
*/
void	control_keys_projections(int key, t_meta *meta)
{
	if (key == KEY_P)
	{
		parallel_x(&meta->map);
		map_pipeline(meta, FREE);
	}
	if (key == KEY_O)
	{
		parallel_x(&meta->map);
		map_pipeline(meta, FREE);
	}
	if (key == KEY_I)
	{
		isometric(&meta->map);
		map_pipeline(meta, FREE);
	}
	if (key == KEY_B || key == KEY_V)
	{
		if (meta->keys.b_keyctrl || key == KEY_V)
			meta->map.brange -= 0.0001;
		else
			meta->map.brange += 0.0001;
	}
	if (key == KEY_G)
		meta->map.b_geo = !meta->map.b_geo;
}

void	control_keys_showhide(int key, t_meta *meta)
{
	if (key == KEY_D)
		meta->map.b_dots = !meta->map.b_dots;
	if (key == KEY_L)
		meta->map.b_lines = !meta->map.b_lines;
	if (key == KEY_S)
		meta->map.b_stars = !meta->map.b_stars;
	if (key == KEY_H)
		meta->map.b_shadow = !meta->map.b_shadow;
	if (key == KEY_Z)
		xpm_load_init_rend();
}

/* 
*	This function add grades to the control structure depends the key pressed
*/
void	control_keys_angle_control0(int key, t_meta *meta)
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

void	control_keys_angle_control1(int key, t_meta *meta)
{
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
}
