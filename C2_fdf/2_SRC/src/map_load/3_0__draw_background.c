/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0__draw_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 10:58:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
*	This function generate all the pixel colors and fill the img array propertly
*/

void	generate_background(t_meta *meta, int backcolor, int menucolor)
{
	int	axis[2];
	int	pixel;
	int	color;

	backcolor = get_color(meta, backcolor);
	menucolor = get_color(meta, menucolor);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pixel = (axis[Y] * meta->bitmap.lines) + (axis[X] * 4);
			set_color(&meta->bitmap.buffer[pixel], \
						meta->bitmap.endian, color, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}
