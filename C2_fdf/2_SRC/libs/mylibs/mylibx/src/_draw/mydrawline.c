/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydrawline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 16:16:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibx.h"

//void	wire_line(t_point *map_points, t_meta *meta, int density, int line);
//int		draw_line(t_meta *meta, t_point start, t_point end);

/**
 * This uses the Digital Differential Analyzer (DDA) algorithm to draw a line
 * between two points in a wireframe. The points are specified by the indices 
 * `i` and `i + x_max * density` in the `map_points` array.
 *
 * The DDA algorithm works by calculating the intermediate points between the
 * start and end points of the line, ensuring a smooth and accurate line drawing.
 *
 * Parameters:
 * - map_points: An array representing the wireframe points.
 * - i: The starting index of the line in the map_points array.
 * - x_max: The maximum number of points in the x-direction.
 * - density: density factor determines spacing between points in the wireframe.
 */
/* void	mydrawline(t_meta *meta, t_point *map_points)
{
	int	i;
	int	density;

	if (!meta->map.b_lines)
		return ;
	density = 8 / meta->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < meta->map.len)
	{
		wire_line (&map_points[i], meta, density, i / meta->map.limits.axis[X]);
		i = i + meta->map.limits.axis[X] * density;
	}
} */

/* 
*	This function checks if any map_points is out of the limits of the screen
*/
/* void	wire_line(t_point *map_points, t_meta *meta, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int)meta->map.limits.axis[X])
	{
		x_end = i + density;
		if (x_end >= (int)meta->map.limits.axis[X])
			x_end = (int)meta->map.limits.axis[X] - 1;
		y_end = i + (int)meta->map.limits.axis[X] * density;
		if (map_points[i].paint)
		{
			draw_line(meta, map_points[i], map_points[x_end]);
			if (line + density < (int)meta->map.limits.axis[Y])
				draw_line(meta, map_points[i], map_points[y_end]);
		}
		i += density;
	}
} */

/*
*	This function checks if the whole line is out of the window to avoid the 
*	operations and getting better the performance.
*	Then calculate all the map_points of the line with the DDA's line algorithm
*/

/* int	draw_line(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
		return (0);
	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	delta.axis[X] /= pixels;
	delta.axis[Y] /= pixels;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(meta, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (1);
} */
