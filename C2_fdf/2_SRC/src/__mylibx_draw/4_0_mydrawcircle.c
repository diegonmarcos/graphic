/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0_mydrawcircle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 13:14:30 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function implements Bresenham's circle drawing algorithm, which
* creates a filled circle with a specified radius at a given point on the screen.
*
*
*	Bresenham's algorithm works by tracking points along the circumference of 
* the circle in one octant (1/8th of the circle), and then using symmetry 
* to determine the points in the other seven octants.
*
* 	The change tracks the incremental changes needed for the algorithm, 
* and radius_error keeps track of the accumulated error in the approximation.
* The function also creates a pixel structure that inherits its color from the
* input point, which will be used to render each pixel  of the circle.
*
*/
void	mydrawcircle(t_meta *meta, t_point *map_points)
{
	int	i;

	if (!meta->map.b_dots)
		return ;
	i = 0;
	while (i < meta->map.len)
	{
		if (map_points[i].paint)
			draw_dot(meta, map_points[i], 1);
		i++;
	}
}

/*
*	This function draw a circule in t_point position and with r radius
*/
void	draw_dot(t_meta *meta, t_point point, int radius)
{
	int		axis[2];
	int		change[2];
	int		radius_error;
	t_point	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.color = point.color;
	while (axis[X] >= axis[Y])
	{
		dot_util(meta, pixel, point, axis[Y]);
		dot_util(meta, pixel, point, axis[X]);
		axis[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			axis[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}

/*
*	Auxiliar function to draw a circle
*/
void	dot_util(t_meta *meta, t_point pixel, t_point point, int coord)
{
	int	i;

	i = point.axis[X];
	while (i <= point.axis[X] + coord)
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] + coord;
		myputpixel(meta, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] - coord;
		myputpixel(meta, pixel);
		i++;
	}
}
