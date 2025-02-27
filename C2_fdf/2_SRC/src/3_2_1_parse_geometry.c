/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2.1.parse_geometry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:34 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:42:25 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
*	This function iterate len points of the array and 
*	divide de z axis by divisor
*/
void	z_division(t_point *proyect, float divisor, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		proyect[i].axis[Z] = proyect[i].axis[Z] / divisor;
		i++;
	}
}

/*
*	Iterate all the point to move the z value depending the range 
*	and the x and y position
*/

void	bending(t_point *points, int len, float range)
{
	int		i;
	float	vv;

	i = 0;
	while (i < len)
	{
		vv = ((points[i].axis[X] * points[i].axis[X]) * (range)) + \
		(points[i].axis[Y] * points[i].axis[Y]) * (range);
		points[i].axis[Z] = points[i].axis[Z] - vv;
		i++;
	}
}
