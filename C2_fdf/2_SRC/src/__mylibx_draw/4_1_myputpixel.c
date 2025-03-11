/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_1_myputpixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 13:14:53 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

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
int	myputpixel(t_meta *meta, t_point pixel)
{
	int	mypixel;
	int	alpha;
	int	color;

	alpha = 0;
	color = color_convert_depth(meta, pixel.color);
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -10;
	if (!valid_pixel(pixel))
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	myputpixel_writer(&meta->bitmap.buffer[mypixel], \
		meta->bitmap.endian, color, alpha);
	return (0);
}

/*
*	set_color writes the pixel data to the calculated memory location. 
* This helper function handles the actual writing of color data, 
* taking into account the 
* system's endianness (byte order), the color value, and the alpha blending value
*
* ednianness is the byte order in which the bytes of a multi-byte data type
* are stored in memory.
*/
void	myputpixel_writer(char *buffer, int endian, int color, int alpha)
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

