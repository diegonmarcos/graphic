/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1__draw_parsemap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:14 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 13:55:27 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * @file 3_2__draw_parsemap.c
 * @brief This file contains the implementation of functions to modify points 
 * in a space.
 *
 * This source file is part of a larger project that involves manipulating and 
 * rendering points in a 2D or 3D space. The primary purpose of this file is to 
 * call various functions that perform transformations, modifications, and 
 * other operations on points within the space. These operations may include 
 * translation, rotation, scaling, and other geometric transformations.
 *
 * The following key functionalities are provided by this file:
 * - Initialization of point data structures.
 * - Application of geometric transformations to points.
 * - Parsing and interpreting map data to modify points accordingly.
 * - Integration with other modules to ensure seamless data flow and 
 *   transformation.
 */
void	parse_map(t_meta *meta, t_point *map_points)
{
	z_division(map_points, meta->map.zdivisor, meta->map.len);
	if (meta->map.b_geo)
		spherize(&meta->map, map_points);
	bending(map_points, meta->map.len, meta->map.brange);
	rotate_x(map_points, map_points, meta->map.ang[X], meta->map.len);
	rotate_y(map_points, map_points, meta->map.ang[Y], meta->map.len);
	rotate_z(map_points, map_points, meta->map.ang[Z], meta->map.len);
	if (meta->map.b_geo && meta->map.b_shadow)
		shadow (map_points, meta->map.len);
	ortogonal_projection (map_points, map_points, meta->map.len);
	scale (map_points, meta->map.scale, meta->map.len);
	traslate(map_points, meta->map.source, meta->map.len);
}
