/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0___vars_ini1.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 09:25:23 by dinepomu         ###   ########.fr       */
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
