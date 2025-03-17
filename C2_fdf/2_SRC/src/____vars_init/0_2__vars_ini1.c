/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_2__vars_ini1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 12:29:02 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	vars_init_map1(t_meta *meta)
{
	meta->map.proportion = meta->map.limits.axis[Z] / meta->map.limits.axis[X];
	if (meta->map.proportion > 0.5)
		meta->map.zdivisor = meta->map.proportion * 30;
	meta->map.b_auto_rotate = 0;
}
