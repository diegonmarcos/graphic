/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.3..draw_drawning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:41 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/15 11:11:12 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	drawing(t_meta *meta, t_point *proyect, int fit)
{
	if (meta->map.b_stars)
		generate_stars(meta);
	if (fit)
		go_fit(meta, proyect);
	if (meta->map.b_lines)
		wired(meta, proyect);
	if (meta->map.b_dots)
		doted(meta, proyect);
}
