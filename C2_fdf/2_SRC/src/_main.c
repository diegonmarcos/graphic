/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:01 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/14 16:00:34 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv != 2)
		terminate(ERR_ARGS);
	load_map(&meta.map, argc[1]);
	system_init(&meta);
	if (draw_map(&meta, FIT) < 0)
		halt_exit_program(ERR_MAP);
	system_init_keys(&meta);
	free (meta.map.memory);
	free (meta.map.points);
	return (0);
}
