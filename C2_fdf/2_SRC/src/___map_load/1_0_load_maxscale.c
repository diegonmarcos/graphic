/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_load_maxscale.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:27:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 12:34:25 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * Calculates the maximum scale factor that allows all points to fit within
 * the specified screen boundaries.
 * 
 * @param meta Pointer to the metadata structure containing map information
 * @param map_points Array of map points to be scaled
 * @return The optimal scale factor
 */
float	calculate_scale_factors(float map_width, float map_height, float screen_width, float screen_height)
{
	float scale_x, scale_y, max_scale;

	while (map_width <= 0 || map_height <= 0)
	{
		if (map_width <= 0)
			scale_x = FLT_MAX;
		else
			scale_x = screen_width / map_width;
		if (map_height <= 0)
			scale_y = FLT_MAX;
		else
			scale_y = screen_height / map_height;
		while (scale_x > scale_y)
			scale_x -= 0.01;
		while (scale_y > scale_x)
			scale_y -= 0.01;
		if (scale_x < scale_y)
			max_scale = scale_x;
		else
			max_scale = scale_y;
		if (scale_x != FLT_MAX && scale_y != FLT_MAX)
			break ;
	}
	max_scale *= 0.95;
	return (max_scale);
}

void find_min_max_coordinates(t_point *points, int len, float *min_x, float *max_x, float *min_y, float *max_y)
{
	int	i;
	*min_x = *max_x = points[0].axis[X];
	*min_y = *max_y = points[0].axis[Y];

	i = 1;
	while (i < len)
	{
		if (points[i].axis[X] < *min_x)
			*min_x = points[i].axis[X];
		if (points[i].axis[X] > *max_x)
			*max_x = points[i].axis[X];
		if (points[i].axis[Y] < *min_y)
			*min_y = points[i].axis[Y];
		if (points[i].axis[Y] > *max_y)
			*max_y = points[i].axis[Y];
		i++;
	}
}

void	apply_transformations(t_meta *meta, t_point *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		apply_rotations(meta, &points[i]);
		apply_z_division(meta, &points[i]);
		i++;
	}
}

float	max_scale(t_meta *meta, t_point *map_points)
{
	float min_x, max_x, min_y, max_y;
	float map_width, map_height;
	float screen_width, screen_height;
	t_point *temp_points;
	float max_scale_factor;

	temp_points = (t_point *)malloc(sizeof(t_point) * meta->map.len);
	if (!temp_points)
		return (1.0);

	copy_map(temp_points, meta->map.points, meta->map.len);
	apply_transformations(meta, temp_points, meta->map.len);
	find_min_max_coordinates(temp_points, meta->map.len, &min_x, &max_x, &min_y, &max_y);
	map_width = max_x - min_x;
	map_height = max_y - min_y;
	screen_width = (WINX - MENU_WIDTH - 2 * FIT_MARGIN);
	screen_height = (WINY - 2 * FIT_MARGIN);
	max_scale_factor = calculate_scale_factors(map_width, map_height, screen_width, screen_height);
	free(temp_points);
	return (max_scale_factor);
}
