/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2__map_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:11:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 12:56:20 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	map_render(t_meta *meta, t_point *map_points, int fit)
{
	render_stars(meta);
	fit_to_scale(meta, map_points, fit);
	mydrawframe(meta, map_points);
	mydrawcircle(meta, map_points);
}
