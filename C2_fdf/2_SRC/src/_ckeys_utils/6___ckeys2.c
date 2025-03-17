/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___ckeys2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 13:28:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function handle the colorscheme dependig the key pressed
*/
void	control_keys_colorscheme(int key, t_map *map, t_meta *meta)
{
	if (key == KEY_1)
	{
		map->colors.backcolor = CARBON;
		map->colors.bottomcolor = BLUE;
		map->colors.groundcolor = YELLOW;
		map->colors.topcolor = BRICK_RED;
	}
	if (key == KEY_2)
	{
		map->colors.bottomcolor = YELLOW;
		map->colors.groundcolor = BLUE;
		map->colors.topcolor = BRICK_RED;
	}
	if (key == KEY_3)
	{
		map->colors.backcolor = BLUE;
	}
	if (key == KEY_4)
	{
		map->colors.backcolor = WHITE;
		map->colors.groundcolor = SAFFRON;
		map->colors.bottomcolor = AZUL;
		map->colors.topcolor = BRICK_RED;
	}
	colorize(map, meta);
}

void	control_keys_autorotation(int key, t_meta *meta)
{
	if (key == KEY_E)
	{
		meta->map.b_auto_rotate = !meta->map.b_auto_rotate;
		mlx_loop_hook(meta->vars.mlx, auto_rotation_1, meta);
	}
	if (key == KEY_R)
	{
		meta->map.b_auto_rotate = !meta->map.b_auto_rotate;
		mlx_loop_hook(meta->vars.mlx, auto_rotation_2, meta);
	}
	if (key == KEY_T)
	{
		meta->map.b_auto_rotate = !meta->map.b_auto_rotate;
		mlx_loop_hook(meta->vars.mlx, auto_rotation_3, meta);
	}
	if (key == KEY_Y)
	{
		meta->map.b_auto_rotate = !meta->map.b_auto_rotate;
		mlx_loop_hook(meta->vars.mlx, auto_rotation_4, meta);
	}
	if (key == KEY_U)
	{
		meta->map.b_auto_rotate = !meta->map.b_auto_rotate;
		mlx_loop_hook(meta->vars.mlx, auto_rotation_5, meta);
	}
}

/* 
*	This function increment the ang value by value, checking is under the limits
*/
void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
		*ang = 360 + *ang;
	if (*ang >= 360)
		*ang = *ang - 360;
}

void	win_atrib_ontop(void)
{
	char	command[256];

	usleep(100000);
	ft_snprintf(command, sizeof(command), \
		"wmctrl -r \"=)\" -b add,above || true");
	if (system(command))
		exit(0);
}
