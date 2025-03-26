/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3d_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:41:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 12:38:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#include "mylibx.h"

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
