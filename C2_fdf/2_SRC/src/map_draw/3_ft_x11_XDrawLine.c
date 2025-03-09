/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_x11_XDrawLine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:07:25 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 13:25:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

typedef struct s_points1
{
	unsigned int color0;
	unsigned int color1;
	int			x1;
	int			x0;
	int			y1;
	int			y0;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
} 		t_points1;

/**
 * Bresenham's line algorithm implementation
 * Draws a line between two points (x0,y0) and (x1,y1)
 * Similar to XDrawLine() but implemented for use with MiniLibX
 */
void ft_draw_line(void *mlx_ptr, void *win_ptr, t_points1 *p)
{
	while (1)
	{
		// Draw the current pixel
		mlx_pixel_put(mlx_ptr, win_ptr, p->x0, p->y0, p->color);
		// Check if we've reached the end point
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		p->e2 = 2 * p->err;
		// Update x if needed
		if (p->e2 >= p->dy)
		{
			if (p->x0 == p->x1)
				break ;
			p->err += p->dy;
			p->x0 += p->sx;
		}
		// Update y if needed
		if (p->e2 <= p->dx)
		{
			if (p->y0 == p->y1)
				break ;
			p->err += p->dx;
			p->y0 += p->sy;
		}
	}
}

/**
 * Alternative implementation that draws directly to an image buffer
 * More efficient for MiniLibX as it avoids multiple calls to mlx_pixel_put
 */
void ft_draw_line2(unsigned int *img_data, int img_width, t_points1 *p)
{
	while (1)
	{
		// Calculate gradient color at current position
        float t = (float)step / steps;
        
        int r = r0 + (int)((r1 - r0) * t);
        int g = g0 + (int)((g1 - g0) * t);
        int b = b0 + (int)((b1 - b0) * t);
        
        unsigned int color = (r << 16) | (g << 8) | b;

		// Draw the current pixel if it's within the image bounds
		if (p->x0 >= 0 && p->y0 >= 0 && p->x0 < img_width)
			img_data[p->y0 * img_width + p->x0] = p->color;
		// Check if we've reached the end point
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		p->e2 = 2 * p->err;
		// Update x if needed
		if (p->e2 >= p->dy)
		{
			if (p->x0 == p->x1)
				break ;
			p->err += p->dy;
			p->x0 += p->sx;
		}
		// Update y if needed
		if (p->e2 <= p->dx)
		{
			if (p->y0 == p->y1)
				break ;
			p->err += p->dx;
			p->y0 += p->sy;
		}
	}
}
void	line_variables_init(t_points1 *p)
{
	p->color0 = 0x00FF0000;
	p->x0 = 100;
	p->x1 = 700;
	p->y0 = 100;
	p->y1 = 500;
	p->dx = abs(p->x1 - p->x0);
	p->dy = -abs(p->y1 - p->y0);
	p->sx = -1;
	if (p->x0 < p->x1)
		p->sx = 1;
	p->sy = -1;
	if (p->y0 < p->y1)
		p->sy = 1;
	p->err = p->dx + p->dy;

	// Extract RGB components
    int r0 = (color0 >> 16) & 0xFF;
    int g0 = (color0 >> 8) & 0xFF;
    int b0 = color0 & 0xFF;
    
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;
    
    // Calculate total steps for gradient interpolation
    int steps = max(dx, -dy);
    if (steps == 0) steps = 1; // Avoid division by zero
    
    int step = 0;  // Current step
}

/**
 * Usage with MiniLibX image buffer
 */
void example_usage(void *mlx_ptr, void *win_ptr)
{
	void			*img_ptr;
	int				bpp, size_line, endian;
	unsigned int	*img_data;
	t_points1		p;

	// Initialize Image Variables
	line_variables_init(&p);

	// Create a new image
	img_ptr = mlx_new_image(mlx_ptr, 800, 600);

	// Get image data address
	img_data = (unsigned int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	// Draw a line to the image (assuming 32 bits per pixel)
	ft_draw_line2((unsigned int *)img_data, 800, &p);

	// Put the image to the window
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

/**
 * @brief Draw a line with color gradient using Bresenham's algorithm
 * @param img The image buffer
 * @param width The width of the image
 * @param x0 Starting x-coordinate
 * @param y0 Starting y-coordinate
 * @param x1 Ending x-coordinate
 * @param y1 Ending y-coordinate
 * @param color0 Starting color (RGB)
 * @param color1 Ending color (RGB)
 */
void ft_draw_line_gradient_bresenham(unsigned int *img, int width, int x0, int y0, 
                                    int x1, int y1, unsigned int color0, unsigned int color1)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    int e2;
    
    // Extract RGB components
    int r0 = (color0 >> 16) & 0xFF;
    int g0 = (color0 >> 8) & 0xFF;
    int b0 = color0 & 0xFF;
    
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;
    
    // Calculate total steps for gradient interpolation
    int steps = max(dx, -dy);
    if (steps == 0) steps = 1; // Avoid division by zero
    
    int step = 0;  // Current step
    
    while (1) {
        // Calculate gradient color at current position
        float t = (float)step / steps;
        
        int r = r0 + (int)((r1 - r0) * t);
        int g = g0 + (int)((g1 - g0) * t);
        int b = b0 + (int)((b1 - b0) * t);
        
        unsigned int color = (r << 16) | (g << 8) | b;
        
        // Only draw if within bounds
        if (x0 >= 0 && y0 >= 0 && x0 < width) {
            img[y0 * width + x0] = color;
        }
        
        if (x0 == x1 && y0 == y1) break;
        
        e2 = 2 * err;
        if (e2 >= dy) {
            if (x0 == x1) break;
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx) {
            if (y0 == y1) break;
            err += dx;
            y0 += sy;
        }
        
        step++;
    }
}