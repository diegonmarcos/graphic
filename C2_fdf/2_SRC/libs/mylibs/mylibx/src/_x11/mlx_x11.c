/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_x11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:39:48 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 13:28:12 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibx.h"

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
int	color_convert_depth(int bitxpixel, void *mlx_ptr, int color)
{
	if (bitxpixel != 32)
		color = mlx_get_color_value(mlx_ptr, color);
	return (color);
}
/* int     color_convert_depth(t_meta *meta, int color)
{
        if (meta->bitmap.bitxpixel != 32)
                color = mlx_get_color_value(meta->vars.mlx, color);
        return (color);
} */
