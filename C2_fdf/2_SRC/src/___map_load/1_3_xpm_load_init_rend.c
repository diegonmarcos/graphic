/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_3_xpm_load_init_rend.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:01:54 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/18 07:53:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>

void	center_window(t_xpm *x);
void	terminate_xpm(t_xpm *x);
void	xpm_load_init(t_xpm *x);
void	win_atrib_ontop(void);
void	black_image_initiate(t_xpm *x);
int		draw_xpm(t_xpm *x, void *xpm_ptr);
int		draw_xpm_loop(t_xpm *x);

void	xpm_load_init_rend(void)
{
	t_xpm		x;

	xpm_load_init(&x);
	black_image_initiate(&x);
	mlx_loop_hook(x.mlx_ptr, draw_xpm_loop, &x);
	mlx_loop(x.mlx_ptr);
}

void	xpm_load_init(t_xpm *x)
{
	x->win_height = 75;
	x->win_width = 75;
	x->xpm_path = "maps/xpm/enemy_01.xpm";
	x->xpm_path2 = "maps/xpm/enemy_02.xpm";
	x->line = 0;
	x->column = 0;
	x->image_width_x = 0;
	x->image_height_y = 0;
	x->image_pos_x = 10;
	x->image_pos_y = 10;
	x->bpp = 0;
	x->sl = 0;
	x->en = 0;
	x->frame_count = 0;
	x->mlx_ptr = mlx_init();
	x->win_ptr = mlx_new_window(x->mlx_ptr, x->win_width, x->win_height, "=)");
	x->vars.mlx = x->mlx_ptr;
	x->vars.win = x->win_ptr;
	x->xpm_ptr = mlx_xpm_file_to_image(x->mlx_ptr, x->xpm_path, \
				&x->image_width_x, &x->image_height_y);
	x->xpm_ptr2 = mlx_xpm_file_to_image(x->mlx_ptr, x->xpm_path2, \
				&x->image_width_x, &x->image_height_y);
}

void	black_image_initiate(t_xpm *x)
{
	x->black_img = mlx_new_image(x->mlx_ptr, x->image_width_x, \
		x->image_height_y);
	x->black_ptr = mlx_get_data_addr(x->black_img, &x->bpp, &x->sl, &x->en);
	ft_memset(x->black_ptr, 0, x->image_width_x * x->image_height_y);
}

int	draw_xpm_loop(t_xpm *x)
{
	x->frame_count++;
	if (x->frame_count == 16000)
		terminate(0, 0, "0", (t_meta *)x);
	if (x->frame_count % 1600 < 800)
		draw_xpm(x, x->xpm_ptr);
	else
		draw_xpm(x, x->xpm_ptr2);
	return (0);
}

int	draw_xpm(t_xpm *x, void *xpm_ptr)
{
	int	line;
	int	column;

	line = 0;
	while (line < x->win_height / x->image_height_y)
	{
		column = 0;
		while (column < x->win_width / x->image_width_x)
		{
			mlx_put_image_to_window(x->mlx_ptr, x->win_ptr, xpm_ptr, \
						column * x->image_width_x, line * x->image_height_y);
			column++;
		}
		line++;
	}
	return (0);
}
