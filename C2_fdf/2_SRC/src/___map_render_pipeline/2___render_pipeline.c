/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2___render_pipeline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:57 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 10:46:16 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * @file 3___map_draw.c
 * @brief This file contains functions and logic for drawing maps.
 * 
 * This source file is part of the map drawing module of the application. 
 * It includes functions that handle the rendering of maps, applying various 
 * transformations and modifiers such as translation (x, y, z) and scaling. 
 * The file ensures that the map is drawn correctly according to the specified 
 * parameters and fits within the desireddimensions if the 'fit' parameter 
 * is set to 1.
 * 
 * The main functionalities provided by this file include:
 * - Applying transformations to map coordinates.
 * - Scaling the map to fit within a specified area.
 * - Handling different rendering modes and options.
 * 
 * map->renders is incremented each time the map is drawn.
 * 
 * generate_background() is used to create the background for the map.
 * copy_map() is used to create a copy of the map points for rendering.
 * map_transformation() is used to apply transformations to the map points.
 * drawing() is used to render the map on the screen.
 * 
 * draw_menu() is used to display the menu and other information.
 * map->performance stores the time taken to draw the map.
 */
int	map_pipeline(t_meta *meta, int fit)
{
	t_point	*map_points;
	clock_t	t;

	t = clock();
	map_points = malloc (meta->map.len * sizeof(t_point));
	if (!map_points)
		terminate1(ERR_MEM, meta);
	meta->map.renders = meta->map.renders + 1;
	copy_map(meta->map.points, map_points, meta->map.len);
	map_transformation(meta, map_points, fit);
	map_render(meta, map_points);
	free (map_points);
	t = clock() - t;
	meta->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
