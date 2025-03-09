/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2__drawning_gofit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 10:58:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function iterate n times until get the scale needed
*	to fit the screen.
*/

void	go_fit(t_meta *meta, t_point *proyect)
{
	meta->map.source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	meta->map.source.axis[Y] = WINY / 2;
	meta->map.source.axis[Z] = 0;
	meta->map.scale = 1;
	copy_map(meta->map.points, proyect, meta->map.len);
	parse_map(meta, proyect);
	while (!(limits(proyect, meta->map.len)))
	{
		copy_map(meta->map.points, proyect, meta->map.len);
		parse_map(meta, proyect);
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
