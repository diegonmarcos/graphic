/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_load_mapsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/09 10:58:10 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function determinates the max values x, y, z of the map
*	and terminate if the maps has different line sizes.
*/
void	map_size(t_map *map)
{
	static int	i = -1;
	static int	num_elems = 0;	

	while (map->memory[++i])
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->memory[i]) && \
			(map->memory[i + 1] == ' ' || map->memory[i + 1] == '\n' || \
			map->memory[i + 1] == '\0'))
			num_elems++;
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y]++;
			if (map->limits.axis[X] != 0 && (map->limits.axis[X] != num_elems))
				terminate(ERR_LINE);
			else
				map->limits.axis[X] = num_elems;
			num_elems = 0;
		}
	}
	if (num_elems > 0 && (map->limits.axis[X] != num_elems))
		terminate(ERR_LINE);
	map->limits.axis[Y]++;
	map->len = map->limits.axis[X] * map->limits.axis[Y];
}
