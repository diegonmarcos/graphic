/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___utils_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:31 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/12 11:44:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/* 
*	This function handle when a key is relased
*/
int	key_release(int key, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (key == KEY_CMD)
		meta->keys.b_keyctrl = 0;
	return (0);
}

/* 
*	This function handle every time a mouse button is relased
*/
int	mouse_release(int button, int x, int y, void *param)
{
	t_meta	*meta;

	(void)x;
	(void)y;
	meta = (t_meta *)param;
	if (button == 1)
		meta->keys.b_mouse_l = 0;
	if (button == 2 || button == 3)
		meta->keys.b_mouse_r = 0;
	return (0);
}


/* 
*	This function increment the ang value by value, checking is under the limits
*/
void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
		*ang = 360 + *ang;
	if (*ang >= 360)
		*ang = *ang - 360;
}

int	auto_rotation_1(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (meta->map.b_auto_rotate)
	{
		key_press(KEY_RIGHT, meta);
	}
	return (0);
}

int	auto_rotation_2(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (meta->map.b_auto_rotate)
	{
		key_press(KEY_RIGHT, meta);
		key_press(KEY_UP, meta);
	}
	return (0);
}
