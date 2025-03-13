/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7___utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:42 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 15:08:14 by dinepomu         ###   ########.fr       */
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

/* 
*	This function handle the program shut down when a error happends
*/
void	terminate(char *s, t_meta *meta)
{
	if (errno == 0)
		ft_dprintf(2, "Error: %s\n", strerror(errno));
	else
		perror(s);
	mlx_destroy_display(meta->vars.mlx);
	exit(1);
}

void	terminate1(char *s, t_meta *meta)
{
	if (errno == 0)
		ft_dprintf(2, "Error: %s\n", strerror(errno));
	else
		perror(s);
	free(meta->map.memory);
	mlx_destroy_display(meta->vars.mlx);
	exit(1);
}

/* 
*	This function handle the program shut down
*	mlx_destroy_window(meta->vars.mlx, meta->vars.win); not use this one
*/
int	halt_exit_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	free(meta->map.memory);
	free(meta->map.points);
	mlx_destroy_display(meta->vars.mlx);
	exit(0);
}
