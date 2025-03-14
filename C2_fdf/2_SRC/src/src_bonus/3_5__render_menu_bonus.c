/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5__render_menu_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:00:01 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/14 16:03:19 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
/**
* #MENU
* M will show/hide the menu
* ESC will halt the program
* CMD will change the behavior of the keys
* A will reset the map to the original state
* F will fit the map to the window
* C will center the map
*
* #PROJECTIONS VIEWS
* P will apply the parallel projection
* I will apply the isometric projection
* B will aplying bending to the map
* G will apply the geo transformation
*
* #SHOW HIDE
* D will show/hide the dots
* L will show/hide the lines
* H will show/hide the shadow
* S will show/hide the stars
* 
* #ZOOM (ANGLES MOVE)
* SUM will zoom in
* RES will zoom out
* Q will change the angle of the map for the x axis
* W will change the angle of the map for the y axis
*
* #COLOR SCHEME
* 1 will change the color scheme to the default
* 2 will change the color scheme to the second
* 3 will change the color scheme to the third
* 4 will change the color scheme to the fourth
*
* # AUTO ROTATION
* E will start/stop the auto rotation 1
* R will start/stop the auto rotation 2
* T will start/stop the auto rotation 3
* Y will start/stop the auto rotation 4
*/
void	draw_mapinfo(t_meta *meta)
{
	int		line;

	line = MAPINFO_BOX;
	print_str(meta, MENU_TAB, line, "//// MAP INFO ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Size:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.len);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Xmax:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.limits.axis[X]);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Ymax:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.limits.axis[Y]);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Zmax:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.limits.axis[Z]);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Zmin:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.zmin);
	line += LINE_SIZE;
}

void	draw_info(t_meta *meta)
{
	int		line;

	line = DRAWINFO_BOX;
	print_str(meta, MENU_TAB, line, "//// DRAW INFO ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Reenders:");
	print_nbr(meta, MENU_TAB + 100, line, meta->map.renders);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Performance(ms):");
	print_nbr(meta, MENU_TAB + 170, line, meta->map.performance * 1000);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "X, Y, Z: [   ] [   ] [   ]");
	print_nbr(meta, MENU_TAB + 100, line, meta->map.ang[X]);
	print_nbr(meta, MENU_TAB + 160, line, meta->map.ang[Y]);
	print_nbr(meta, MENU_TAB + 220, line, meta->map.ang[Z]);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Zoom:");
	print_nbr(meta, MENU_TAB + 80, line, meta->map.scale);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Z Divisor:");
	print_nbr(meta, MENU_TAB + 110, line, meta->map.zdivisor);
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Blending:");
	print_nbr(meta, MENU_TAB + 100, line, meta->map.brange * 10000);
}

void	draw_menu0(t_meta *meta)
{
	int		line;

	line = MENU0_BOX;
	print_str(meta, MENU_TAB, line, "//// MENU ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "M: Show/hide the menu");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "ESC: Halt the program");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "CMD: Change key behavior");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "A: Reset map");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "F: Fit map to window");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "C: Center map");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "P: Parallel projection");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "I: Isometric projection");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "B: Apply bending");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "G: Geo transformation");
	line += LINE_SIZE;
}

void	draw_menu1(t_meta *meta)
{
	int		line;

	line = MENU1_BOX;
	print_str(meta, MENU_TAB, line, "//// SHOW HIDE ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "D: show/hide the dots");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "L: show/hide the lines");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "H: show/hide the shadow");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "S: show/hide the stars");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "//// ZOOM (ANGLES MOVE) ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "SUM: zoom in");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "RES: zoom out");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Q: change angle for x axis");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "W: change angle for y axis");
	line += LINE_SIZE;
}

void	draw_menu2(t_meta *meta)
{
	int		line;

	line = MENU2_BOX;
	print_str(meta, MENU_TAB, line, "//// COLOR SCHEME ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "1:  change to color scheme default");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "2:  change to color scheme second");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "3:  change to color scheme third");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "4:  change to color scheme fourth");
	line += LINE_SIZE;
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "//// AUTO ROTATION ////");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "E: start/stop the auto rotation 1");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "R: start/stop the auto rotation 2");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "T: start/stop the auto rotation 3");
	line += LINE_SIZE;
	print_str(meta, MENU_TAB, line, "Y: start/stop the auto rotation 4");
}

void	render_menu(t_meta *meta)
{
	if (!meta->map.b_menu)
		return ;
	draw_info(meta);
	draw_mapinfo(meta);
	draw_menu0(meta);
	draw_menu1(meta);
	draw_menu2(meta);
}
