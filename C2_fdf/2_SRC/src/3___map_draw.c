/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3___map_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:57 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 13:15:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
*	This function draw the proyection of map->points acording all
/**
 * @file 3___map_draw.c
 * @brief This file contains functions and logic for drawing maps in the application.
 * 
 * This source file is part of the map drawing module of the application. It includes
 * functions that handle the rendering of maps, applying various transformations and
 * modifiers such as translation (x, y, z) and scaling. The file ensures that the map
 * is drawn correctly according to the specified parameters and fits within the desired
 * dimensions if the 'fit' parameter is set to 1.
 * 
 * The main functionalities provided by this file include:
 * - Applying transformations to map coordinates.
 * - Scaling the map to fit within a specified area.
 * - Handling different rendering modes and options.
 * 
 * The functions in this file are designed to be efficient and handle large maps with
 * minimal performance overhead. Proper error handling and validation are implemented
 * to ensure robustness.
 * 
 * @note This file is part of a larger project and interacts with other modules for
 *       complete functionality. Ensure that dependencies are correctly managed.
 * 
 * @author 
 * @date 
 * @version 
 */
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the 
*	scale needed to fit the screen.
*/
int	draw_map(t_meta *meta, int fit)
{
	t_point	*proyect;
	clock_t	t;

	t = clock();
	proyect = malloc (meta->map.len * sizeof(t_point));
	if (!proyect)
		terminate1(ERR_MEM, meta);
	meta->map.renders = meta->map.renders + 1;
	generate_background(meta, meta->map.colors.backcolor, \
						meta->map.colors.menucolor);
	copy_map(meta->map.points, proyect, meta->map.len);
	parse_map(meta, proyect);
	drawing(meta, proyect, fit);
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
							meta->bitmap.img, 0, 0);
	draw_menu(meta);
	free (proyect);
	t = clock() - t;
	meta->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
