/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myputpixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/19 10:54:01 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibx.h"

/*
*	set_color writes the pixel data to the calculated memory location. 
* This helper function handles the actual writing of color data, 
* taking into account the 
* system's endianness (byte order), the color value, and the alpha blending value
*
* ednianness is the byte order in which the bytes of a multi-byte data type
* are stored in memory.
*/
void	myputpixel(char *buffer, int endian, int color, int alpha)
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
