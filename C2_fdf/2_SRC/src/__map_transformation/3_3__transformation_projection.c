/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1__transformation_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:34 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 10:06:40 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
* - Scaling of points to fit the display
* - multiply each point the by scale
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
*   Calculate len "points" of the array to ortho projection
*   and store in "projection" array.
*/
void	ortogonal_projection(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	matrix3_init(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(projection_matrix, points[i]);
		i++;
	}
}
