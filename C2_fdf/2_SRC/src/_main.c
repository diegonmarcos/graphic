/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:01 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 10:41:22 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * @brief Implementation of the FdF project from 42 school.
 *
 * @details
 * @par Details:
 *  - The FdF project is a graphical representation project that involves 
 *    creating a wireframe model of a 3D landscape from a given set of 
 *    coordinates. The goal is to display the model in a window and allow 
 *    for basic interactions such as zooming and rotating.
 *
 * @par Usage Make: make MAP=[map]
 * 	- [42]		make MAP=42
 * 	- [mars]	make MAP=mars
 * 	- [earth]	make MAP=earth
 * 	- [fractol]	make MAP=fractol
 *  - [mandel]	make MAP=mandel
 * 
 * @par Usage Program: ./fdf maps/[X]
 * 	- [parm2] @b argv: file containing the coordinates of the landscape.
 * 	- return: @b return void
 *	- [X]:
 *		- maps/42.fdf
 *		- maps/mars.fdf
 *		- maps/fract.fdf
 *		- maps/julia.fdf
 * @code
 * 	make &&\
 * 	./fdf maps/42.fdf
 * @endcode
 *
 * @par Usage Make:
 * 	- [static analysis]	make linting
 *	- [leaks]			make leaks
 */
int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv != 2)
		terminate(ERR_ARGS);
	vars_init(&meta);
	map_load(&meta.map, argc[1], &meta);
	vars_init_map1(&meta);
	map_pipeline(&meta, FIT);
	vars_init_x11_events(&meta);
	free (meta.map.memory);
	free (meta.map.points);
	return (0);
}
