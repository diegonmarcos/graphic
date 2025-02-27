/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3...map_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:57 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 09:53:55 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
*	This function draw the proyection of map->points acording all
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the 
*	scale needed to fit the screen.
*/
int	draw_map(t_meta *meta, int fit)
{
	t_point	*proyect;
	clock_t	t;

	t = clock();
	proyect = malloc (meta->map.len * sizeof(t_point));
	if (!proyect)
		terminate1(ERR_MEM, meta);
	meta->map.renders = meta->map.renders + 1;
	generate_background(meta, meta->map.colors.backcolor, \
						meta->map.colors.menucolor);
	copy_map(meta->map.points, proyect, meta->map.len);
	parse_map(meta, proyect);
	drawing(meta, proyect, fit);
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
							meta->bitmap.img, 0, 0);
	draw_menu(meta);
	free (proyect);
	t = clock() - t;
	meta->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
