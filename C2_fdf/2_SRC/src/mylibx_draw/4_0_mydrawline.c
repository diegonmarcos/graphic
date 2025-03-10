/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0_mydrawline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:49 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 15:05:29 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This ft iterate all the points of the wire array and draw a line between:
*	--> wire[i] and wire [i + density]
*	--> wire[i] and wire [i + x_max * density]
*/
void	wired(t_meta *meta, t_point *wire)
{
	int	i;
	int	density;

	density = 8 / meta->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < meta->map.len)
	{
		wire_line (&wire[i], meta, density, i / meta->map.limits.axis[X]);
		i = i + meta->map.limits.axis[X] * density;
	}
}

/* 
*	This function checks if any point is out of the limits of the screen
*/
void	wire_line(t_point *point, t_meta *meta, int density, int line)
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
		if (point[i].paint)
		{
			draw_line(meta, point[i], point[x_end]);
			if (line + density < (int)meta->map.limits.axis[Y])
				draw_line(meta, point[i], point[y_end]);
		}
		i += density;
	}
}

/*
*	This function checks if the whole line is out of the window to avoid the 
*	operations and getting better the performance.
*	Then calculate all the point of the line with the Bresenham's line algorithm
*/

int	draw_line(t_meta *meta, t_point start, t_point end)
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
}
