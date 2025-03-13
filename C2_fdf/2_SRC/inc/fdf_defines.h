/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:39:58 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 08:53:02 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef FDF_DEFINES_H
# define FDF_DEFINES_H

/* ***************************************************************** */
/* 1.1 Defines														 */
/* ***************************************************************** */
# define BLOCK_READ 500000

//# define WINX 1920
//# define WINY 1080
//# define WINX 2048
//# define WINY 1152
# define WINX 2400
# define WINY 1600

# define X 0
# define Y 1
# define Z 2

# define LAT 0
# define LONG 1

# define MENU_WIDTH			350
# define FIT_MARGIN			50

# define FIT				1
# define FREE				0

/* ***************************************************************** */
/* 1.1 Draw Menu													 */
/* ***************************************************************** */
# define CONTROL_BOX		650
# define DRAWINFO_BOX		40
# define MAPINFO_BOX		280
# define COLORSCHEME_BOX	480
# define LINE_SIZE			30
# define MENU_TAB			30

/* ***************************************************************** */
/* 1.1 Error Handling												 */
/* ***************************************************************** */
# define ERR_ARGS		"Incorrect number of arguments, expected 1"
# define ERR_OPEN		"Error opening the file"
# define ERR_READ		"Error reading the file"
# define ERR_SPLIT		"Error splitting the line"
# define ERR_LINE		"Error: nº of elements is different for each line"
# define ERR_EMPTY		"Error: the file is empty or wrongly formatted"
# define ERR_MEM		"Memory error"
# define ERR_MAP		"Map Error"

#endif
