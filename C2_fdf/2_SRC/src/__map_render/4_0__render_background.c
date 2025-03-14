/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0__render_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/14 16:09:00 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
* - This function generate all the pixel colors 
* - Fill the img array propertly
* - The fucntion get_color will convert to a 32 bit color the color received
*/

void	render_background(t_meta *meta, int backcolor, int menucolor)
{
	int	axis[2];
	int	pixel;
	int	color;

	backcolor = color_convert_depth(meta->bitmap.bitxpixel, \
			meta->vars.mlx, backcolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = backcolor;
			else
				color = backcolor;
			pixel = (axis[Y] * meta->bitmap.lines) + (axis[X] * 4);
			myputpixel(&meta->bitmap.buffer[pixel], \
						meta->bitmap.endian, color, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}
