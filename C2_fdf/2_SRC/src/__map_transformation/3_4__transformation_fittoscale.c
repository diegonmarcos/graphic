/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4__transformation_fittoscale.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 10:44:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function iterate n times until get the scale needed
*	to fit the screen.
*/

void	fit_to_scale(t_meta *meta, t_point *map_points, int fit)
{
	if (!fit)
		return ;
	meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	meta->map.source.axis[Y] = WINY / 2;
	meta->map.source.axis[Z] = 0;
	meta->map.scale = 1;
	copy_map(meta->map.points, map_points, meta->map.len);
	map_transformation1(meta, map_points);
	while (!(limits(map_points, meta->map.len)))
	{
		copy_map(meta->map.points, map_points, meta->map.len);
		map_transformation1(meta, map_points);
		meta->map.scale = meta->map.scale + 0.2;
	}
}

int	limits(t_point *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[X] < (MENU_WIDTH + FIT_MARGIN) || \
			points[i].axis[X] > (WINX - FIT_MARGIN))
			return (1);
		if (points[i].axis[Y] < FIT_MARGIN || \
			points[i].axis[Y] > (WINY - FIT_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

/* void fit_to_scale(t_meta *meta, t_point *map_points, int fit)
{
    if (!fit)
        return;
        
    // Set center position
    meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
    meta->map.source.axis[Y] = WINY / 2;
    meta->map.source.axis[Z] = 0;
    
    // Calculate the optimal scale directly
    meta->map.scale = calculate_max_scale(meta, map_points);
    
    // Apply transformations once with the calculated optimal scale
    copy_map(meta->map.points, map_points, meta->map.len);
    map_transformation(meta, map_points);
} */