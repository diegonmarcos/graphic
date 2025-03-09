/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1__draw_parsemap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:14 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 10:58:10 by dinepomu         ###   ########.fr       */
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
 * The functions defined in this file are designed to be modular and reusable, 
 * allowing for flexible manipulation of points based on different 
 * requirements. The file is structured to ensure that each function performs a 
 * specific task, making the code easier to maintain and extend.
 *
 * The following key functionalities are provided by this file:
 * - Initialization of point data structures.
 * - Application of geometric transformations to points.
 * - Parsing and interpreting map data to modify points accordingly.
 * - Integration with other modules to ensure seamless data flow and 
 *   transformation.
 *
 * Usage:
 * - Include this file in your project to access the point modification 
 *   functions.
 * - Ensure that the necessary dependencies and data structures are defined 
 *   before calling these functions.
 * - Call the appropriate functions to perform the desired transformations on 
 *   your points.
 *
 * Dependencies:
 * - This file may depend on other modules for data structures, mathematical 
 *   operations, and rendering functions.
 * - Ensure that all required headers and libraries are included in your 
 *   project.
 *
 * Example:
 * @code
 * // Example usage of functions in 3_2__draw_parsemap.c
 * #include "3_2__draw_parsemap.h"
 *
 * int main() {
 *     // Initialize points and other necessary data structures
 *     Point points[MAX_POINTS];
 *     initialize_points(points, MAX_POINTS);
 *
 *     // Apply transformations to points
 *     translate_points(points, MAX_POINTS, 10, 20);
 *     rotate_points(points, MAX_POINTS, 45);
 *
 *     // Parse map data and modify points accordingly
 *     parse_map_data("mapfile.txt", points, MAX_POINTS);
 *
 *     // Render or further process the modified points
 *     render_points(points, MAX_POINTS);
 *
 *     return 0;
 * }
 * @endcode
 *
 * @note Ensure that the map data file is correctly formatted and accessible.
 * @note Handle any errors or exceptions that may arise during point 
 * modifications.
 *
 * @see Other related files and modules for additional functionalities.
 */
void	parse_map(t_meta *meta, t_point *proyect)
{
	z_division(proyect, meta->map.zdivisor, meta->map.len);
	if (meta->map.b_geo)
		spherize(&meta->map, proyect);
	bending(proyect, meta->map.len, meta->map.brange);
	rotate_x(proyect, proyect, meta->map.ang[X], meta->map.len);
	rotate_y(proyect, proyect, meta->map.ang[Y], meta->map.len);
	rotate_z(proyect, proyect, meta->map.ang[Z], meta->map.len);
	if (meta->map.b_geo && meta->map.b_shadow)
		shadow (proyect, meta->map.len);
	ortogonal_projection (proyect, proyect, meta->map.len);
	scale (proyect, meta->map.scale, meta->map.len);
	traslate(proyect, meta->map.source, meta->map.len);
}
