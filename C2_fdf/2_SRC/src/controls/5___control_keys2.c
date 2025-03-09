/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5...control_keys2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:32:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
void	control_colorscheme(int key, t_map *map)
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
	colorize(map);
}
