/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2___sys_ini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 10:41:28 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

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
void	system_init_0(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
}

void	system_init(t_meta *meta)
{
	meta->map.renders = 0;
	meta->map.proportion = meta->map.limits.axis[Z] / meta->map.limits.axis[X];
	if (meta->map.proportion > 0.5)
		meta->map.zdivisor = meta->map.proportion * 30;
	meta->keys.b_keyctrl = 0;
	meta->keys.b_mouse_l = 0;
	meta->keys.b_mouse_r = 0;
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, \
	"FDF - dinepomu");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
		&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}
