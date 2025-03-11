/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1___map_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 16:40:58 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	Inicialize the structure
*	Get the map_size
*	Check if the map is valid
*	Read the map
*	Load each point to the structure
*/
void	map_load(t_map *map, char *path)
{
	int	fd;

	map_ini(map, 1);
	fd = open(path, O_RDONLY);
	if (fd < 2)
		terminate(ERR_OPEN);
	map->memory = get_next_line_join(fd);
	close (fd);
	map_size(map);
	map_get_points(map);
	colorize(map);
	go_polar(map);
//	map_checker(map);
	ft_printf("\nLoading GUI\n");
}
