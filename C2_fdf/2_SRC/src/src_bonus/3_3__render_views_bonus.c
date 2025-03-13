/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3__render_views_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:15 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 12:58:46 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
*	Set the values to draw ISOMETRIC view
*/
void	isometric(t_map *map)
{
	map->b_geo = 0;
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 30;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}

/*
*	Set the values to draw PARALLEL view
*/
void	parallel_x(t_map *map)
{
	map->b_geo = 0;
	map->ang[X] = 90;
	map->ang[Y] = 90;
	map->ang[Z] = 0;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}

void	parallel_y(t_map *map)
{
	map->b_geo = 0;
	map->ang[X] = 0;
	map->ang[Y] = 90;
	map->ang[Z] = 90;
	map->brange = 0;
	map->source.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y] = WINY / 2;
}

void	shadow(t_point *points, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[Z] < 0)
			points[i].paint = 0;
		else
			points[i].paint = 1;
		i++;
	}
}

void	render_stars(t_meta *meta)
{
	int		i;
	t_point	star;
	int		lim_x[2];
	int		lim_y[2];

	if (!meta->map.b_stars)
		return ;
	if (meta->map.b_geo == 0)
		return ;
	lim_x[0] = meta->map.source.axis[X] - (meta->map.radius * meta->map.scale);
	lim_x[1] = meta->map.source.axis[X] + (meta->map.radius * meta->map.scale);
	lim_y[0] = meta->map.source.axis[Y] - (meta->map.radius * meta->map.scale);
	lim_y[1] = meta->map.source.axis[Y] + (meta->map.radius * meta->map.scale);
	i = 0;
	while (i < 200)
	{
		star.axis[X] = rand() % WINX;
		star.axis[Y] = rand() % WINY;
		star.color = WHITE;
		if ((star.axis[X] < lim_x[0] || star.axis[X] > lim_x[1]) \
		|| ((star.axis[Y]) < lim_y[0] || star.axis[Y] > lim_y[1]))
			draw_dot(meta, star, 2);
		i++;
	}
}
