/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.1..draw_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:16:54 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
*	This function copy len points of the array from src to dst
*/

void	copy_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
*	This function set the color value to 32bits value in case of need
*/

int	get_color(t_meta *meta, int color)
{
	if (meta->bitmap.bitxpixel != 32)
		color = mlx_get_color_value(meta->vars.mlx, color);
	return (color);
}

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
