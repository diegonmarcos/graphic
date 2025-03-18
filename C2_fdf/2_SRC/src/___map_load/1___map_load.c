/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1___map_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 07:31:59 by dinepomu         ###   ########.fr       */
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
void	map_load(t_map *map, char *path, t_meta *meta)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 2)
		terminate(0, 1, ERR_OPEN, meta);
	map->memory = get_next_line_join(fd);
	close (fd);
	map_size(map, meta);
	map_get_points(map, meta);
	colorize(map, meta);
	ft_printf("\nLoading GUI\n");
}
