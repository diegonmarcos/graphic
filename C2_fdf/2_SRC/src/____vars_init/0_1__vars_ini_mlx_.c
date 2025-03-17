/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_1__vars_ini_mlx_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:58:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/17 13:40:00 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

/**
 * Initializes the MiniLibX library and assigns the returned pointer to the 
 * `mlx` member of the `vars` structure within the `meta` object.
 *
 * This function call is essential for setting up the graphical environment 
 * and must be called before any other MiniLibX functions are used.
 *
 * @note Ensure that the `meta` and `vars` structures are properly allocated 
 * and initialized before calling this function.
 *
 * 1. mlx_init():
 *    - Input: None
 *    - Output: Returns a void pointer (void*) that serves as the MiniLibX 
 * connection identifier
 *    - Purpose: Establishes a connection to the X server and initializes the
 *  MiniLibX library
 *    - Usage: This pointer must be stored and passed to most other 
 * MiniLibX functions
 *
 * 
 * 2. mlx_new_window(meta->vars.mlx, WINX, WINY, "FDF - dinepomu"):
 *    - Inputs:
 *      - meta->vars.mlx: The MiniLibX connection pointer returned by mlx_init()
 *      - WINX, WINY: Integer constants defining window width and 
 * height in pixels
 *      - "FDF - dinepomu": String constant for the window title
 *    - Output: Returns a void pointer (void*) that serves as the window 
 * identifier
 *    - Purpose: Creates a new graphical window with specified dimensions 
 * and title
 *    - Usage: This window pointer is stored and used for drawing operations 
 * and event binding
 *
 * 
 * 3. mlx_new_image(meta->vars.mlx, WINX, WINY):
 *    - Inputs:
 *      - meta->vars.mlx: The MiniLibX connection pointer
 *      - WINX, WINY: Image dimensions in pixels (same as window size 
 * for full-window images)
 *    - Output: Returns a void pointer (void*) that represents the image
 *    - Purpose: Creates an off-screen image buffer for drawing before display
 *    - Usage: Image operations are performed on this buffer before being 
 * put to the window
 *
 * 
 * 4. mlx_get_data_addr(meta->bitmap.img, &meta->bitmap.bitxpixel, 
 * &meta->bitmap.lines, &meta->bitmap.endian):
 *    - Inputs:
 *      - meta->bitmap.img: Image pointer from mlx_new_image()
 *      - &meta->bitmap.bitxpixel: Pointer to an integer to store bits per pixel
 *      - &meta->bitmap.lines: Pointer to an integer to store line size in bytes
 *      - &meta->bitmap.endian: Pointer to an integer to store endianness info
 *    - Output: Returns a char pointer to the actual image data buffer
 *    - Purpose: Provides direct access to the image's memory for pixel 
 * manipulation
 *    - Usage: The returned address points to the first pixel's data, and 
 * can be manipulated
 * directly using the bits_per_pixel, size_line, and endian information
 */
void	vars_init_x11(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, \
	"FDF - dinepomu");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
		&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}

/**
 * @brief Initializes X11 event hooks for the given meta structure.
 *
 * This function sets up various event hooks for the X11 window system using the
 * MiniLibX library. It binds specific event handlers to the window, allowing
 * the program to respond to keyboard and mouse events.
 *
 * @param meta1 Pointer to a t_meta structure containing the necessary
 *              information for setting up the event hooks.
 *
 * The following events are hooked:
 * - Key press (event 2)
 * - Key release (event 3)
 * - Mouse press (event 4)
 * - Mouse release (event 5)
 * - Mouse move (event 6)
 * - Window close (event 17)
 *
*The << operator is the bitwise left shift operator, which shifts the bits of the
* left operand to the left by the number of positions specified by the right
* operand.In this case, the right operand is 6, meaning that the bits in 1L will
*   be shifted 6 positions to the left.
*
* When 1L is shifted left by 6 positions, the result is a binary number where the
* bit in the 6th position (counting from the right, starting at position 0) 
* is set to 1, and all other bits are 0. 
*In binary, this looks like 0000...1000000, which is equivalent to the value 64.
*
* In the context of the MiniLibX (MLX) library used in the file, this expression 
* is likely being used as an event mask for X Window System event handling. 
* Event masks in X11 programming are typically represented as bitmasks, 
* where each bit corresponds to a specific type of event. 
* By shifting 1 to the left by 6 positions, the code is creating 
* a mask that specifically selects the event type associated with bit position 6,
* which in X11 could correspondto ButtonMotionMask.
*
* Common event codes include(hich type of event is being handled):
* 2: KeyPress - A key was pressed
* 3: KeyRelease - A key was released
* 4: ButtonPress - A mouse button was pressed
* 5: ButtonRelease - A mouse button was released
* 6: MotionNotify - The mouse moved
* 17: DestroyNotify - The window is being closed
* 
* Mask Parameter (Third Parameter)
* The mask parameter specifies which specific properties of that event
*For key events, the masks include:

* 1L << 0 (KeyPressMask): Interested in which key was pressed
* 1L << 1 (KeyReleaseMask): Interested in which key was released
* For mouse events, masks might include:
* 1L << 2 (ButtonPressMask): Interested in which button was pressed
* 1L << 3 (ButtonReleaseMask): Interested in which button was released
* 1L << 6 (ButtonMotionMask): mouse motion while buttons are pressed
* 17 and 0 is used for the window close event
*/
void	vars_init_x11_events(t_meta *meta1)
{
	t_meta	meta;

	meta = *meta1;
	mlx_hook(meta.vars.win, 2, 1L << 0, key_press, &meta);
	mlx_hook(meta.vars.win, 3, 1L << 1, key_release, &meta);
	mlx_hook(meta.vars.win, 4, 1L << 2, mouse_press, &meta);
	mlx_hook(meta.vars.win, 5, 1L << 3, mouse_release, &meta);
	mlx_hook(meta.vars.win, 6, 1L << 6, mouse_move, &meta);
	mlx_hook(meta.vars.win, 17, 0, halt_exit_program, &meta);
	mlx_loop(meta.vars.mlx);
}
