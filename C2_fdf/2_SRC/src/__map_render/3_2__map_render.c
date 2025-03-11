/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_2__map_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:11:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	map_render(t_meta *meta, t_point *map_points)
{
	render_stars(meta);
	mydrawframe(meta, map_points);
	mydrawcircle(meta, map_points);
}
