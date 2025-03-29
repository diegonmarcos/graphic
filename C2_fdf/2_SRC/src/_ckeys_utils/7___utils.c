/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7___utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:42 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/29 18:32:53 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	print_nbr(t_meta *meta, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, NUMBER_COLOR, str);
	free (str);
}

void	print_str(t_meta *meta, int x, int y, char *str)
{
	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, TEXT_COLOR, str);
}

/**
 * @brief 
 * 
 * @param param 
 * @return int 
 * 
 * 1. mlx_destroy_window(mlx_ptr, win_ptr)
 * Can be used to close one window while keeping others open
 * When you have multiple windows and want to close just one
 * 
 * 2. mlx_destroy_display(mlx_ptr)
 * Closes the connection to the X display server
 * Must be called after all windows are destroyed
 */
void	terminate(int stage, int exit_mode, char *s, t_meta *meta)
{
	if (stage >= 1)
		free(meta->map.memory);
	if (stage > 1)
		free(meta->map.points);
	if (exit_mode)
	{
		if (errno == 0)
			ft_dprintf(2, "Error: %s\n", strerror(errno));
		else
			perror(s);
	}
	if (meta->bitmap.img && stage != -1)
		mlx_destroy_image(meta->vars.mlx, meta->bitmap.img);
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	mlx_destroy_display(meta->vars.mlx);
	free(meta->vars.mlx);
	exit(exit_mode);
}

int	terminate_x_click(void *meta)
{
	terminate(2, 0, "0", meta);
	return (0);
}
