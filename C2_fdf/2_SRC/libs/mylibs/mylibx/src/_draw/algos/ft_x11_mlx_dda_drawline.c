/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x11_mlx_dda_drawline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:55 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 17:38:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#include "mylibx.h"

/**
 * This uses the Digital Differential Analyzer (DDA) algorithm to draw a line
 * between two points in a wireframe. The points are specified by the indices 
 * `i` and `i + x_max * density` in the `map_points` array.
 *
 * The DDA algorithm works by calculating the intermediate points between the
 * start and end points of the line, ensuring a smooth and accurate line drawing.
 *
 * Parameters:
 * - map_points: An array representing the wireframe points.
 * - i: The starting index of the line in the map_points array.
 * - x_max: The maximum number of points in the x-direction.
 * - density: density factor determines spacing between points in the wireframe.
 */
