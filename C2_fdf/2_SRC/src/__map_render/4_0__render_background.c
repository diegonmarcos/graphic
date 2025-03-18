/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_0__render_background.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 08:45:19 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	draw_mapinfo(t_meta *meta);
void	draw_info(t_meta *meta);
void	draw_menu0(t_meta *meta);
void	draw_menu1(t_meta *meta);
void	draw_menu2(t_meta *meta);

/*
* - This function generate all the pixel colors 
* - Fill the img array propertly
* - The fucntion get_color will convert to a 32 bit color the color received
*/
void	render_background(t_meta *meta, int backcolor)
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

void	render_menu(t_meta *meta)
{
	if (!BONUS)
		return ;
	if (!meta->map.b_menu)
		return ;
	draw_info(meta);
	draw_mapinfo(meta);
	draw_menu0(meta);
	draw_menu1(meta);
	draw_menu2(meta);
}
