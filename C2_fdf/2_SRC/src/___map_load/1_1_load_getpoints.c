/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_load_getpoints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:32 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 15:15:04 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * This function is responsible for loading points from a map file.
 * It reads the map data from the specified file path and processes it to extract
 * the coordinates of the points. The extracted points are then stored in a
 * data structure for further use in the application.
 *
 * map structure expected:
 * [hexa_color] [elevation],[hexa_color] [elevation], ...
 * [hexa_color] [elevation],[hexa_color] [elevation], ...
 * 0x290543 1,0x290543 1,
 * 0x290543 1,0x290543 1,
 */
void	map_get_points(t_map *map, t_meta *meta)
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
			num_points += load_points(line, map, num_line++, meta);
			ft_printf("\r  %d points reading...", num_points);
			if (map->memory[i] == '\0')
				break ;
		}
	}
	free (line);
	ft_printf("\r %d Map_Get_Points readed\n", num_points);
}

/* 
*	Splits the info of line to storage the points in the map->point array. 
*	Using map->len as index of the array
*/
int	load_points(char *line, t_map *map, int numline, t_meta *meta)
{
	char		**splited;
	int			i;
	static int	point_index = 0;

	splited = ft_split(NAME_M, line, ' ');
	i = 0;
	while (splited[i] && splited[i][0] != '\n')
	{
		if (!valid_point(&splited[i][0]))
			terminate(ERR_EMPTY, meta);
		map->points[point_index].axis[Z] = ft_atoi(&splited[i][0]);
		map->points[point_index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[point_index].axis[Y] = numline - map->limits.axis[Y] / 2;
		map->points[point_index].paint = 1;
		map->points[point_index].color = DEFAULT_COLOR;
		map->points[point_index].hex_color = has_hexcolors (splited[i]);
		if (map->limits.axis[Z] < map->points[point_index].axis[Z])
			map->limits.axis[Z] = map->points[point_index].axis[Z];
		if (map->zmin > map->points[point_index].axis[Z])
			map->zmin = map->points[point_index].axis[Z];
		i++;
		point_index++;
	}
	ft_free_array_2d(splited);
	return (i);
}

int	valid_point(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

int	has_hexcolors(char *line)
{
	char	**color;
	int		get_color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(NAME_M, line, ',');
		get_color = ft_strol(color[1] + 2, NULL, 16);
		ft_free_array_2d(color);
		return (get_color);
	}
	else
		return (0);
}
