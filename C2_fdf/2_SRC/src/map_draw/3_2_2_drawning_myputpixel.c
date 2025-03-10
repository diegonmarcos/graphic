/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2_2_drawning_myputpixel.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 10:58:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
*	This function calculate the position of the pixel in the img array:
*		array_pixe_position = pixel.axis[y] * WINX * 4 + 4 * pixel.axis[y]
*	and fill the 4 colorbytes calling the set_color function
*/
int	my_putpixel(t_meta *meta, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	if (meta->bitmap.bitxpixel != 32)
		pixel.color = mlx_get_color_value(meta->vars.mlx, pixel.color);
	set_color(&meta->bitmap.buffer[mypixel], \
		meta->bitmap.endian, pixel.color, alpha);
	return (0);
}

/*
*	This function fills 4 bytes of the given address whith the values of colors
*	depending the andian
*      endian = 1 --> Most significant (Alpha) byte first
*      endian = 0 --> Least significant (Blue) byte first
*/
void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}
