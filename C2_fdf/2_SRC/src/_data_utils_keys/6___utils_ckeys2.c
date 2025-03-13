/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___utils_ckeys2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 07:51:25 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function handle the colorscheme dependig the key pressed
*/
void	control_colorscheme(int key, t_map *map, t_meta *meta)
{
	if (key == KEY_1)
	{
		map->colors.backcolor = CARBON;
		map->colors.bottomcolor = BLUE;
		map->colors.groundcolor = YELLOW;
		map->colors.topcolor = BRICK_RED;
	}
	if (key == KEY_2)
	{
		map->colors.bottomcolor = YELLOW;
		map->colors.groundcolor = BLUE;
		map->colors.topcolor = BRICK_RED;
	}
	if (key == KEY_3)
	{
		map->colors.backcolor = BLUE;
	}
	if (key == KEY_4)
	{
		map->colors.backcolor = WHITE;
		map->colors.groundcolor = SAFFRON;
		map->colors.bottomcolor = AZUL;
		map->colors.topcolor = BRICK_RED;
	}
	colorize(map, meta);
}
