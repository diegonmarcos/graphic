/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.1.load_getpoints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:32 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 10:03:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
[explain]
*/
void	map_get_points(t_map *map)
{
	int			i;
	char		*line;
	char		*last_line;
	static int	num_points = 0;
	static int	num_line = 0;

	last_line = map->memory;
	line = NULL;
	i = 0;
	map->points = ft_calloc(map->len, sizeof(t_point));
	while (++i)
	{
		if (map->memory[i] == '\n' || map->memory[i] == '\0')
		{
			free (line);
			line = ft_substr(NAME_M, last_line, 0, &map->memory[i] - last_line);
			last_line = &map->memory[i + 1];
			num_points += load_points(line, map, num_line++);
			ft_printf("\r ▶ %d points reading...", num_points);
			if (map->memory[i] == '\0')
				break ;
		}
	}
	free (line);
	ft_printf("\r %d Map_Get_Points readed\n", num_points);
}
