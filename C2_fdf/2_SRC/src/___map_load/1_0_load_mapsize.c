/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_load_mapsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 07:31:59 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/*
* This function calculates:
*	- the number of elements in a line
*	- the number of lines
*	- the total number of elements in the map
*	- the size of the map 
*
* num_elems is the number of elements in a line.
* map->limits.axis[X] is the number of elements in a line.
* map->limits.axis[Y] is the number of lines.
* map->len is the total number of elements in the map.
*
* map->memory is a string with the content of the file.
*
*/
void	map_size(t_map *map, t_meta *meta)
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
				terminate( 0, 1, ERR_LINE, meta);
			else
				map->limits.axis[X] = num_elems;
			num_elems = 0;
		}
	}
	if (num_elems > 0 && (map->limits.axis[X] != num_elems))
		terminate(0, 1, ERR_LINE, meta);
	map->limits.axis[Y]++;
	map->len = map->limits.axis[X] * map->limits.axis[Y];
}
