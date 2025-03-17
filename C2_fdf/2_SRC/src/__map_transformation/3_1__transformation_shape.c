/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1__transformation_shape.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 10:06:34 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/** 
*/
void	go_polar(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
	steps_y = M_PI / (map->limits.axis[Y]);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X]) * steps_x;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[LAT] = (map->points[i].axis[Y] + \
			(map->limits.axis[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}
}

void	spherize(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}

/* 
*	Z-divisor to control the height effect
*/
void	z_division(t_point *map_points, float divisor, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		map_points[i].axis[Z] = map_points[i].axis[Z] / divisor;
		i++;
	}
}

/**
 * @brief bending transformation function.
 *
 *  The bending function modifies the Z-axis value of each point in the given 
 * array of points based on a bending transformation formula.
 *
 *  This formula applies a quadratic transformation to the X and Y coordinates 
 * of each point,
 * scaled by the range parameter, and subtracts the result from the Z
 *  coordinate.
 * 
 *  The bending function effectively reduces the Z coordinate of each 
 * point based
 * on the squared values of the X and Y coordinates, scaled by the range 
 * factor.
 * This creates a bending effect where points with larger X and Y values 
 * experience a greater reduction in their Z coordinate.
 */
void	bending(t_point *points, int len, float range)
{
	int		i;
	float	vv;

	i = 0;
	while (i < len)
	{
		vv = ((points[i].axis[X] * points[i].axis[X]) * (range)) + \
		(points[i].axis[Y] * points[i].axis[Y]) * (range);
		points[i].axis[Z] = points[i].axis[Z] - vv;
		i++;
	}
}
