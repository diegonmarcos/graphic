/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:58:34 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 11:02:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function handle when a key is pressed
*/
int	key_press(int key, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	angle_control(key, meta);
	control_keys1(key, meta);
	control_keys2(key, meta);
	control_keys3(key, meta);
	if (key >= KEY_1 && key <= KEY_4)
		control_colorscheme(key, &meta->map, meta);
	map_pipeline(meta, FREE);
	return (0);
}

/* 
*	This function handle every time a mouse button is pressed
*/
int	mouse_press(int button, int x, int y, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (button == 1)
	{
		meta->keys.b_mouse_l = 1;
		meta->keys.last_click_l.axis[X] = x;
		meta->keys.last_click_l.axis[Y] = y;
	}
	if (button == 2 || button == 3)
	{
		meta->keys.b_mouse_r = 1;
		meta->keys.last_click_r.axis[X] = x;
		meta->keys.last_click_r.axis[Y] = y;
	}
	if (button == 5)
	{
		if (meta->map.scale > 2)
			meta->map.scale = meta->map.scale / 1.5;
	}
	if (button == 4)
		meta->map.scale = meta->map.scale * 1.5;
	map_pipeline(meta, FREE);
	return (0);
}

/* 
*	This function handle every time the mouse is moved
*/
int	mouse_move(int x, int y, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (meta->keys.b_mouse_l)
	{
		angle(&meta->map.ang[X], (int)meta->keys.last_click_l.axis[Y] - y);
		angle(&meta->map.ang[Y], (int)meta->keys.last_click_l.axis[X] - x);
		meta->keys.last_click_l.axis[X] = x;
		meta->keys.last_click_l.axis[Y] = y;
		map_pipeline(meta, FREE);
	}
	if (meta->keys.b_mouse_r)
	{
		meta->map.source.axis[X] -= ((int)meta->keys.last_click_r.axis[X] - x);
		meta->map.source.axis[Y] -= ((int)meta->keys.last_click_r.axis[Y] - y);
		meta->map.source.axis[Z] = 0;
		meta->keys.last_click_r.axis[X] = x;
		meta->keys.last_click_r.axis[Y] = y;
		map_pipeline(meta, FREE);
	}
	return (0);
}