/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_3_map_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:01:54 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 13:13:42 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	maps_input_validation(void);
void	maps_load_validation(void);

void	map_checker(char c)
{
	if (c == 'i')
		maps_input_validation();
	else
		maps_load_validation();
}


void	maps_input_validation(void)
{
/* 	int	color;

	color = color_convert_depth(meta, pixel.color); */
}


void	maps_load_validation(void)
{
/* 	if (!valid_pixel(pixel))
		return (-1); */
}
