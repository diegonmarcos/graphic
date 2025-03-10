/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_2_drawning_doted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 12:51:20 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This ft iterate all the points of the array and draw a dot for each point
*/
void	doted(t_meta *meta, t_point *project)
{
	int	i;

	i = 0;
	while (i < meta->map.len)
	{
		if (project[i].paint)
			draw_dot(meta, project[i], 1);
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
		my_putpixel(meta, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] - coord;
		my_putpixel(meta, pixel);
		i++;
	}
}
