/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_0_mydrawline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/14 16:06:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
*  The DDA algorithm works by calculating the intermediate points between the
* start and end points of the line, ensuring a smooth and accurate line drawing.
* the function determine which pairs of points should be connected with lines, 
* considering the density parameter, it  choose which endpoints to connect.
* The density parameter determines how sparse or dense the wireframe will be 
* by skipping points in the grid.
* 	1. It calculates the exact floating-point slope 
* (`delta.axis[X] /= pixels; delta.axis[Y] /= pixels;`)
* 	2. It incrementally adds this slope to the current position for each step 
* (`pixel.axis[X] += delta.axis[X]; pixel.axis[Y] += delta.axis[Y];`)
* 	3. It uses `sqrt()` to calculate the total number of pixels
* 	4. It calculates the gradient color at each step using linear interpolation
* 	5. It draws the pixel at each intermediate point
* 	6. It updates the current position based on the error accumulation
*
* 
* General 3D wireframe vs just a 2D grid-based representation
* 	- The 3D wireframe representation is more complex and requires additional
*  calculations to determine the perspective and depth of the objects.
* 	- The 2D grid-based representation is simpler and more straightforward,
*  as it only requires drawing lines between points on a 2D grid.
*
* Bresenham's algorithm vs DDA algorithm
*  Bresenham's algorithm would use integer arithmetic only, with 
* error accumulation, decision variables, rather than floating-point increments.
*
* Parameters:
* - map_points: An array representing the wireframe points.
* - i: The starting index of the line in the map_points array.
* - density: density factor determines spacing between points in the wireframe.
* - line: The current line number in the wireframe.
* - meta: The meta structure containing the map and window data.
*/
void	mydrawframe(t_meta *meta, t_point *map_points)
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
		mydrawframe_row_lines(&map_points[i], \
			meta, density, i / meta->map.limits.axis[X]);
		i = i + meta->map.limits.axis[X] * density;
	}
}

/* 
* The function takes four parameters: an array of t_point structures (map_points)
*   which contains the coordinates and other properties of each point in the map,
*   a pointer to a t_meta structure (meta) that holds various metadata about the 
*   rendering context, an integer density that controls how many points to skip 
*   between connections(controlling the detail level of the wireframe),
*   and an integer line that indicates the current line being processed in the 
*   overall rendering loop.
*
* The function iterates through points in the current row of the map,
*   determined by the line parameter. It processes points at regular intervals 
*   defined by the density parameter, allowing for adaptive level-of-detail 
*   rendering. For each point that needs to be processed, it calculates 
*   two destination points: one horizontally along the X-axis (x_end) and one 
*   vertically along the Y-axis (y_end).
*
* Parameters:
* - pixel: The point to check.
* x_end: The end point of the line in the x-axis.
* y_end: The end point of the line in the y-axis.
*/
void	mydrawframe_row_lines(t_point *map_points, t_meta *meta, \
			int density, int line)
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
			mydrawline(meta, map_points[i], map_points[x_end]);
			if (line + density < (int)meta->map.limits.axis[Y])
				mydrawline(meta, map_points[i], map_points[y_end]);
		}
		i += density;
	}
}

/*
*	This function checks if the whole line is out of the window to avoid the 
*	operations and getting better the performance.
*	Then calculate all the map_points of the line with the DDA's algorithm inputs
* Parameters:
* - start: The starting point of the line.
* - end: The ending point of the line.
* - pixels: The total number of pixels in the line.
* - len: The current length of the line.
* - delta: The slope of the line.
* - pixel: The current pixel to draw.
*/

int	mydrawline(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

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
		pixel.color = color_convert_depth(meta->bitmap.bitxpixel, \
			meta->vars.mlx, pixel.color);
		myputpixel_check(meta, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (1);
}

/*
*	Once the function confirms that the pixel is within bounds, it calculates 
* the exact memory position (mypixel) where the pixel data should be stored in 
* the linear bitmap buffer. 
*
*	This calculation converts the 2D coordinates into a 1D memory offset using 
* the formula (Y * WINX * 4) + (X * 4), where 
* the multiplication by 4 accounts for the four bytes typically used to 
* store each pixel's color information (likely RGBA components).
* 
*   Checks if the display's bit depth (bitxpixel) is not the standard 32 bits
* 
* 	Calls set_color to write the pixel data
*/
int	myputpixel_check(t_meta *meta, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -100;
	if (!valid_pixel(pixel))
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	myputpixel(&meta->bitmap.buffer[mypixel], \
		meta->bitmap.endian, pixel.color, alpha);
	return (0);
}

/*
*	This function checks if the point is in the windows limit to avoid draw it
*/
int	valid_pixel(t_point pixel)
{
	if (pixel.axis[X] < 0 || pixel.axis[X] > WINX)
		return (0);
	if (pixel.axis[Y] < 0 || pixel.axis[Y] > WINY)
		return (0);
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (0);
	return (1);
}
