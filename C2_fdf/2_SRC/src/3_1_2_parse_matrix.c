/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_2_parse_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:26 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/08 14:56:57 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
*   Calculate len "points" of the array with the "ang" rotation in X axis
*   and store in "projection" array.
*/

void	rotate_x(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = cos(rad);
	projection_matrix[1][2] = -sin(rad);
	projection_matrix[2][1] = sin(rad);
	projection_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(projection_matrix, points[i]);
		i++;
	}
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Y axis
*   and store in "projection" array.
*/

void	rotate_y(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(projection_matrix);
	projection_matrix[0][0] = cos(rad);
	projection_matrix[0][2] = sin(rad);
	projection_matrix[1][1] = 1;
	projection_matrix[2][0] = -sin(rad);
	projection_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(projection_matrix, points[i]);
		i++;
	}
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Z axis
*   and store in "projection" array.
*/
void	rotate_z(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(projection_matrix);
	projection_matrix[0][0] = cos(rad);
	projection_matrix[0][1] = -sin(rad);
	projection_matrix[1][0] = sin(rad);
	projection_matrix[1][1] = cos(rad);
	projection_matrix[2][2] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(projection_matrix, points[i]);
		i++;
	}
}

/*
*   Calculate len "points" of the array to orto projection
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
