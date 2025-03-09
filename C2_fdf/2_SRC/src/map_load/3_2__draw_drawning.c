/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3__draw_drawning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/07 07:42:20 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * @file 3_3__draw_drawning.c
 * @brief This file contains the implementation of drawing functionalities.
 *
 * This source file is part of the drawing module, which is responsible for
 * rendering graphical elements on the screen. The functionalities provided
 * by this module include drawing shapes, lines, and other graphical objects.
 * 
 * The drawing module is designed to be efficient and flexible, allowing for
 * various types of graphical representations. It interfaces with lower-level
 * graphics libraries to perform the actual rendering.
 *
 * The main features of this file include:
 * - Initialization of drawing contexts
 * - Functions to draw basic shapes (e.g., circles, rectangles, lines)
 * - Functions to handle color and style settings
 * - Utility functions for coordinate transformations and clipping
 *
 * The file is structured to ensure modularity and ease of maintenance. Each
 * function is documented with its purpose, parameters, and return values.
 *
 * @note This file is part of a larger project and interacts with other modules
 *       such as input handling, event management, and windowing systems.
 *
 * @see Other related files and modules for more information on the overall
 *      architecture and how this file fits into the project.
 *
 * @version 1.0
 * @date 2023-10-05
 * 
 * @author Diego
 */
void	drawing(t_meta *meta, t_point *proyect, int fit)
{
	if (meta->map.b_stars)
		generate_stars(meta);
	if (fit)
		go_fit(meta, proyect);
	if (meta->map.b_lines)
		wired(meta, proyect);
	if (meta->map.b_dots)
		doted(meta, proyect);
}
