/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4___map_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:11:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 12:29:02 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 *  
 * After establishing the background, the function proceeds to render the actual 
 * wireframe model through two complementary approaches. 
 *
 * First, `mydrawframe` is 
 * called to draw the wireframe structure of the map, connecting the points with 
 * lines to represent the 3D topology. 
 * 
 * This is followed by `mydrawcircle`, which 
 * adds point markers or nodes at significant vertices in the wireframe, 
 * enhancing the visual clarity of the model's structure.
 * 
 * Once all the rendering to the internal buffer is complete, the function calls 
 * mlx_put_image_to_window
 * 
 * , which is a core function from the MiniLibX graphics 
 * library. This function transfers the rendered image from the memory buffer 
 * (stored in `meta->bitmap.img`) to the actual display window. The parameters 
 * passed include the MLX connection pointer, the window identifier, the image 
 * pointer, and the coordinates (0, 0) indicating that the image should be 
 * displayed at the top-left corner of the window.
 * 
 */
void	map_render(t_meta *meta, t_point *map_points)
{
	render_background(meta, meta->map.colors.backcolor);
	render_stars(meta);
	mydrawframe(meta, map_points);
	mydrawcircle(meta, map_points);
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
							meta->bitmap.img, 0, 0);
	render_menu(meta);
}
