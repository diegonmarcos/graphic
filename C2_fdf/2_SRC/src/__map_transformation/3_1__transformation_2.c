/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1__transformation_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:34 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/14 15:17:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
* - Scaling of points to fit the display
* - multiply each point the by scale
*/
void	scale(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] * scale;
		points[i].axis[Y] = points[i].axis[Y] * scale;
		points[i].axis[Z] = points[i].axis[Z] * scale;
		i++;
	}
}

/*
*  - Translation of points to position them correctly perfoming the 
*	"move" traslation
*/
void	traslate(t_point *points, t_point move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] + move.axis[X];
		points[i].axis[Y] = points[i].axis[Y] + move.axis[Y];
		points[i].axis[Z] = points[i].axis[Z] + move.axis[Z];
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

/*
*	Bending for curvature effects
*/

/**
 * @brief bending transformation function.
 *
 *  The bending function modifies the Z-axis value of each point in the given 
 * array of points based on a bending transformation formula.
 *
 *  This formula applies a quadratic transformation to the X and Y coordinates of each point,
 * scaled by the range parameter, and subtracts the result from the Z coordinate.
 * 
 *  The bending function effectively reduces the Z coordinate of each point based
 * on the squared values of the X and Y coordinates, scaled by the range factor.
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
