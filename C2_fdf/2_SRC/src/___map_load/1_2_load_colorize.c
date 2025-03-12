/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2_load_colorize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 10:42:29 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	Colorize all the points of the map apliying a gradient acording the z value
*	of the point and the max and min values of the map.
*/

void	colorize(t_map *map, t_meta *meta)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		load_color((int)map->limits.axis[Z], map->zmin, \
		&map->points[i], map->colors);
		map->points[i].color = color_convert_depth(meta, map->points[i].color);
		i++;
	}
}

/*
*	Acording the z value of the point and de max and min values of the map
*	this function set the color needed of the point received.
*	All the colors are defined in fdf.h 
*/
void	load_color(int max, int min, t_point *point, t_colors colors)
{
	point->paint = 1;
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z] == max)
		point->color = colors.topcolor;
	else if (point->axis[Z] == 0)
		point->color = colors.groundcolor;
	else if (point->axis[Z] == min && min != 0)
		point->color = colors.bottomcolor;
	else if (point->axis[Z] > 0)
		point->color = gradient(colors.groundcolor, colors.topcolor, \
		max, point->axis[Z]);
	else
		point->color = gradient(colors.bottomcolor, colors.groundcolor, \
		-min, - (min - point->axis[Z]));
}

/*
*	This function generates the color of each pixel between starcolor/endcolor
* 	| Red (8 bits) | Green (8 bits) | Blue (8 bits) |
*   	Bits 16-23     Bits 8-15        Bits 0-7
*
* Example:
* 	startcolor = 0x00FF00 	(pure green: 	R=0, 	G=255, 	B=0)
* 	endcolor = 0xFF0000 	(pure red: 		R=255, 	G=0, 	B=0)
* 	len = 100 				(total steps in gradient)
* 	pix = 50 				(halfway point)
*
* The increments would be:
* 	Red increment: (255 - 0) / 100 = 2.55 per step
* 	Green increment: (0 - 255) / 100 = -2.55 per step
* 	Blue increment: (0 - 0) / 100 = 0 per step
*
* At position 50:
* 	New red: 0 + round(50 * 2.55) = 128
* 	New green: 255 + round(50 * -2.55) = 128
* 	New blue: 0 + round(50 * 0) = 0
*/
int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

/*
*	The mlx_int_get_good_color converts from a standard 24-bit RGB color format 
*to whatever color format the current display is using.
*
*  If the display has a color depth of 24 bits or higher (full RGB support):
* The function simply returns the original color value unchanged
* As the display can directly represent all colors
*
*  If the display has a color depth less than 24 bits (older displays):
* The function converts(downsampling operation) the 24-bit RGB color 
* to the display's specific color format
*/
int	color_convert_depth(t_meta *meta, int color)
{
	if (meta->bitmap.bitxpixel != 32)
		color = mlx_get_color_value(meta->vars.mlx, color);
	return (color);
}
