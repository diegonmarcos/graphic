/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_defines_colors.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:39:58 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/13 07:38:50 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef FDF_DEFINES_COLORS_H
# define FDF_DEFINES_COLORS_H

/* ***************************************************************** */
/* 1.1 Collors														 */
/* ***************************************************************** */
# define DEFAULT_COLOR		JAFFA
# define BOTTOM_COLOR		AZUL
# define TOP_COLOR			BRICK_RED
# define GROUND_COLOR		SAFFRON
# define BACK_COLOR			CARBON
# define MENU_COLOR			0x202020
# define TEXT_COLOR			0xEAEAEA	
# define NUMBER_COLOR		0xF3AF3D

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"
# define SH_KNR		"\x1B[0m"
# define SH_KRED	"\x1B[31m"
# define SH_KGRN	"\x1B[32m"
# define SH_KYEL	"\x1B[33m"
# define SH_KBLU	"\x1B[34m"
# define SH_KMAG	"\x1B[35m"
# define SH_KCYN	"\x1B[36m"
# define SH_KWHT	"\x1B[37m"
# define U_ORANGE	"\033[48:5:208m"
# define U_WHITE	"\033[37;7:208m"
# define U_YELLOW	"\033[33;7:208m"
# define U_BLUE		"\033[34;7:208m"

# define RED 		0xc1272d
# define ROJO 		0xc1272d
# define BRICK_RED	0xC2294E
# define BROWN		0x8B4513
# define ORANGE		0xFFA500
# define YELLOW		0xFFD700
# define SAFFRON	0xF3AF3D

# define DARK_GREEN	0x006400
# define VERDE		0x33cc55
# define GREEN		0x33cc55
# define LIME		0x00FF00

# define PURPLE		0x0000FF
# define BLUE		0x1B8EFA
# define AZUL		0x1B8EFA
# define SUPERAZUL	0x0000FF

# define CARBON		0x151515
# define WHITE		0xBBBBBB

# define DISCO		0x9A1F6A
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define FUCSIA 	0xff255c

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
