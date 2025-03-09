/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6___utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:42 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/08 14:55:05 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

/* 
*	This function handle the program shut down when a error happends
*/
void	terminate(char *s)
{
	if (errno == 0)
		ft_dprintf(2, "Error: %s\n", strerror(errno));
	else
		perror(s);
	exit(1);
}

void	terminate1(char *s, t_meta *meta)
{
	if (errno == 0)
		ft_dprintf(2, "Error: %s\n", strerror(errno));
	else
		perror(s);
	free(meta->map.memory);
	exit(1);
}

/* 
*	This function handle the program shut down
*/
int	halt_exit_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	free(meta->map.memory);
	free(meta->map.points);
	exit(0);
}

/*
*	This function set the color value to 32bits value in case of need
* 	but is not being used
*/
int	get_color(t_meta *meta, int color)
{
	if (meta->bitmap.bitxpixel != 32)
		color = mlx_get_color_value(meta->vars.mlx, color);
	return (color);
}
