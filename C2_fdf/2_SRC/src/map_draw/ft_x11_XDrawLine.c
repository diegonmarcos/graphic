/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x11_XDrawLine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:07:25 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 09:10:22 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibx.h"

/**
 * Bresenham's line algorithm implementation
 * Draws a line between two points (x0,y0) and (x1,y1)
 * Similar to XDrawLine() but implemented for use with MiniLibX
 */
void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = -abs(y1 - y0);
	int	sx = -1;
	int	sy = -1;
	int	err = dx + dy;
	int	e2;

	while (x0 < x1)
	{
		sx = 1;
		break ;
	}
	while (y0 < y1)
	{
		sy = 1;
		break ;
	}

	while (1)
	{
		// Draw the current pixel
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
		// Check if we've reached the end point
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		// Update x if needed
		if (e2 >= dy)
		{
			if (x0 == x1)
				break;
			err += dy;
			x0 += sx;
		}
		// Update y if needed
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			err += dx;
			y0 += sy;
		}
	}
}

/**
 * Alternative implementation that draws directly to an image buffer
 * More efficient for MiniLibX as it avoids multiple calls to mlx_pixel_put
 */
void draw_line_to_image(unsigned int *img_data, int img_width, int x0, int y0, 
						 int x1, int y1, unsigned int color)
{
	int	dx = abs(x1 - x0);
	int	dy = -abs(y1 - y0);
	int	sx = -1;
	int	sy = -1;
	int	err = dx + dy;
	int	e2;

	while (x0 < x1)
	{
		sx = 1;
		break ;
	}
	while (y0 < y1)
	{
		sy = 1;
		break ;
	}

	while (1)
	{
		// Draw the current pixel if it's within the image bounds
		if (x0 >= 0 && y0 >= 0 && x0 < img_width)
			img_data[y0 * img_width + x0] = color;
		// Check if we've reached the end point
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		// Update x if needed
		if (e2 >= dy)
		{
			if (x0 == x1)
				break ;
			err += dy;
			x0 += sx;
		}
		// Update y if needed
		if (e2 <= dx)
		{
			if (y0 == y1)
				break ;
			err += dx;
			y0 += sy;
		}
	}
}

/**
 * Usage with MiniLibX image buffer
 */
void	example_usage(void *mlx_ptr, void *win_ptr)
{
	void	*img_ptr;
	int		bpp, size_line, endian;
	char	*img_data;

	// Create a new image
	img_ptr = mlx_new_image(mlx_ptr, 800, 600);

	// Get image data address
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	// Draw a line to the image (assuming 32 bits per pixel)
	draw_line_to_image((unsigned int *)img_data, 800, 100, 100, 700, 500, 0x00FF0000);

	// Put the image to the window
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}
