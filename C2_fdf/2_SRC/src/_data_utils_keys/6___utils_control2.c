/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___utils_control2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:31 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 09:12:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	auto_rotation_1(void *param)
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

int	auto_rotation_2(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (meta->map.b_auto_rotate)
	{
		key_press(KEY_RIGHT, meta);
		key_press(KEY_UP, meta);
		key_press(KEY_Q, meta);
	}
	return (0);
}

int	auto_rotation_3(void *param)
{
	t_meta		*meta;
	static int	frame_counter;

	meta = (t_meta *)param;
	if (meta->map.b_auto_rotate)
	{
		key_press(KEY_LEFT, meta);
		frame_counter++;
		if (frame_counter % 20 < 10)
			key_press(KEY_1, meta);
		if (frame_counter % 20 > 10)
			key_press(KEY_2, meta);
	}
	return (0);
}

int	auto_rotation_4(void *param)
{
	t_meta		*meta;
	static int	frame_counter;

	meta = (t_meta *)param;
	if (meta->map.b_auto_rotate)
	{
		if (frame_counter % 160 < 80)
			key_press(KEY_SUM, meta);
		else
			key_press(KEY_RES, meta);
		frame_counter++;
		if (frame_counter % 20 < 10)
			key_press(KEY_1, meta);
		if (frame_counter % 20 > 10)
			key_press(KEY_2, meta);
	}
	return (0);
}
