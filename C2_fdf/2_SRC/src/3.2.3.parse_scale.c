/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2.3.parse_scale.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:34 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 10:49:56 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


/*
*	Iterates all the points and multiply by scale
*/
void	scale(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] * scale;
		points[i].axis[Y] = points[i].axis[Y] * scale;
		points[i].axis[Z] = points[i].axis[Z] * scale;
		i++;
	}
}

/*
*	Iterates all the points and add the "move" traslation
*/
void	traslate(t_point *points, t_point move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] + move.axis[X];
		points[i].axis[Y] = points[i].axis[Y] + move.axis[Y];
		points[i].axis[Z] = points[i].axis[Z] + move.axis[Z];
		i++;
	}
}
