/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.2.load_gopolar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 10:15:04 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
[explain]
*/
void	go_polar(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
	steps_y = M_PI / (map->limits.axis[Y]);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X]) * steps_x;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[LAT] = (map->points[i].axis[Y] + \
			(map->limits.axis[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}
}
