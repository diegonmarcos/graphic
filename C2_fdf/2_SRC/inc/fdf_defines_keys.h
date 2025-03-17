/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_defines_keys.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:40:24 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 11:02:04 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef FDF_DEFINES_KEYS_H
# define FDF_DEFINES_KEYS_H

# ifdef __linux__
#  define KEY_ESC     65307
#  define KEY_1       49
#  define KEY_2       50
#  define KEY_3       51
#  define KEY_4       52
#  define KEY_5       53
#  define KEY_6       54
#  define KEY_7       55
#  define KEY_8       56
#  define KEY_9       57
#  define KEY_0       58
#  define KEY_SUM     46    // '=' key 61
#  define KEY_RES     45    // '-' key 45
#  define KEY_SUM2    65451 // '+' on numeric keypad
#  define KEY_RES2    65453 // '-' on numeric keypad
#  define KEY_A       97
#  define KEY_S       115
#  define KEY_D       100
#  define KEY_F       102
#  define KEY_H       104
#  define KEY_G       103
#  define KEY_Z       122
#  define KEY_X       120
#  define KEY_C       99
#  define KEY_V       118
#  define KEY_B       98
#  define KEY_Q       113
#  define KEY_W       119
#  define KEY_E       101
#  define KEY_R       114
#  define KEY_Y       121
#  define KEY_T       116
#  define KEY_U       117
#  define KEY_I       105
#  define KEY_P       112
#  define KEY_O		  111
#  define KEY_L       108
#  define KEY_J       106
#  define KEY_K       107
#  define KEY_N       110
#  define KEY_M       109
#  define KEY_TAB     65289
#  define KEY_LEFT    65361
#  define KEY_RIGHT   65363
#  define KEY_DOWN    65364
#  define KEY_UP      65362
#  define KEY_CTRL    65507
#  define KEY_CMD     65507 //65515CMD_MAC
# endif

#endif
