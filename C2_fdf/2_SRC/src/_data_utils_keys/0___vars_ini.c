/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0___vars_ini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 09:36:15 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	var_init_map_bools(t_map *map);
void	var_init_map_0(t_map *map, int total);
void	var_init_map_colors(t_map *map);
void	vars_init_x11(t_meta *meta);

/**
 * @file 2___sys_ini.c
 * @brief System Initialization Source File
 *
 * This file contains the implementation of system initialization functions.
 * It is part of the system startup process and is responsible for setting up
 * the necessary hardware and software components required for the system to
 * operate correctly.
 *
 * The functions in this file typically include:
 * - Hardware initialization: Setting up clocks, configuring GPIOs, initializing
 *   peripherals, etc.
 * - Software initialization: Setting up memory, initializing data structures,
 *   configuring system services, etc.
 * - Boot sequence: Executing the necessary steps to bring the system to a
 *   functional state.
 *
 * The initialization process is critical for ensuring that the system operates
 * reliably and efficiently. Proper initialization helps to avoid issues such as
 * hardware malfunctions, software crashes, and performance bottlenecks.
 *
 * mlx_get_data_addr wil return the address of the first byte of the image buffer
 * mlx_new_image will create a new image in memory
 * mlx_new_window will create a new window
 * mlx_init will initialize the mlx library
 * mlx_loop will start the event loop
 * mlx_hook will set the hooks for the events
 */
void	vars_init(t_meta *meta)
{
	vars_init_x11(meta);
	var_init_map_bools(&meta->map);
	var_init_map0(&meta->map, 1);
	var_init_map_colors(&meta->map);
}

void	vars_init_x11(t_meta *meta)
{
	meta->map.renders = 0;
	meta->vars.mlx = mlx_init();
	meta->keys.b_keyctrl = 0;
	meta->keys.b_mouse_l = 0;
	meta->keys.b_mouse_r = 0;
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, \
	"FDF - dinepomu");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
		&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}

void	var_init_map_bools(t_map *map)
{
	map->b_lines = 1;
	map->b_dots = 0;
	map->b_pluslines = 0;
	map->b_geo = 0;
	map->b_stars = 0;
	map->b_shadow = 1;
	map->b_menu = 0;
}

void	var_init_map0(t_map *map, int total)
{
	if (total)
	{
		map->len = 0;
		map->limits.axis[X] = 0;
		map->limits.axis[Y] = 0;
		map->limits.axis[Z] = 0;
		map->zmin = 0;
	}
	map->fit = FIT;
	map->scale = 1;
	map->zdivisor = 1;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
	map->source.axis[Z] = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
}

void	var_init_map_colors(t_map *map)
{
	map->colors.backcolor = CARBON;
	map->colors.bottomcolor = BLUE;
	map->colors.groundcolor = SAFFRON;
	map->colors.topcolor = BRICK_RED;
	map->colors.menucolor = MENU_COLOR;
}