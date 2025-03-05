/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2___sys_ini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 13:15:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
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
 * @note This file is auto-generated and should not be modified directly. Any
 *       changes should be made in the corresponding configuration files or
 *       scripts that generate this file.
 *
 * @author Diego
 * @date YYYY-MM-DD
 * @version 1.0
 */
[explain]
*/
void	system_init(t_meta *meta)
{
	meta->map.renders = 0;
	meta->map.proportion = meta->map.limits.axis[Z] / meta->map.limits.axis[X];
	if (meta->map.proportion > 0.5)
		meta->map.zdivisor = meta->map.proportion * 30;
	meta->keys.b_keyctrl = 0;
	meta->keys.b_mouse_l = 0;
	meta->keys.b_mouse_r = 0;
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, \
	"FDF - dinepomu");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
		&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}

void	system_init_keys(t_meta *meta1)
{
	t_meta	meta;

	meta = *meta1;
	mlx_hook(meta.vars.win, 2, 1L << 0, key_press, &meta);
	mlx_hook(meta.vars.win, 3, 1L << 1, key_release, &meta);
	mlx_hook(meta.vars.win, 4, 1L << 2, mouse_press, &meta);
	mlx_hook(meta.vars.win, 5, 1L << 3, mouse_release, &meta);
	mlx_hook(meta.vars.win, 6, 1L << 6, mouse_move, &meta);
	mlx_hook(meta.vars.win, 17, 0, halt_exit_program, &meta);
	mlx_loop(meta.vars.mlx);
}
