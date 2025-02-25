/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.2.2.parse_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:26 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:37:34 by dinepomu         ###   ########.fr       */
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
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[1][2] = -sin(rad);
	proyect_matrix[2][1] = sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(proyect_matrix, points[i]);
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
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][2] = sin(rad);
	proyect_matrix[1][1] = 1;
	proyect_matrix[2][0] = -sin(rad);
	proyect_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(proyect_matrix, points[i]);
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
	float	proyect_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix3_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][1] = -sin(rad);
	proyect_matrix[1][0] = sin(rad);
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[2][2] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(proyect_matrix, points[i]);
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
	float	proyect_matrix[3][3];

	matrix3_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix3_multp(proyect_matrix, points[i]);
		i++;
	}
}

/*
*   Multiply a 3 points coordinate "point" by Matrix [3][3]
*   and return the result.
*/
t_point	matrix3_multp(float matrix[3][3], t_point point)
{
	int		i;
	int		k;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = point.color;
		k = 0;
		while (k < 3)
		{
			result.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	return (result);
}
