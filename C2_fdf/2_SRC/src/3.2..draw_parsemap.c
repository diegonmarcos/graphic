/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2..draw_parsemap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:14 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:23:46 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
*	Call all the functions to modify the points in the space
*/

void	parse_map(t_meta *meta, t_point *proyect)
{
	z_division(proyect, meta->map.zdivisor, meta->map.len);
	if (meta->map.b_geo)
		spherize(&meta->map, proyect);
	bending(proyect, meta->map.len, meta->map.brange);
	rotate_x(proyect, proyect, meta->map.ang[X], meta->map.len);
	rotate_y(proyect, proyect, meta->map.ang[Y], meta->map.len);
	rotate_z(proyect, proyect, meta->map.ang[Z], meta->map.len);
	if (meta->map.b_geo && meta->map.b_shadow)
		shadow (proyect, meta->map.len);
	ortogonal_projection (proyect, proyect, meta->map.len);
	scale (proyect, meta->map.scale, meta->map.len);
	traslate(proyect, meta->map.source, meta->map.len);
}
