/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:51:26 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/15 17:36:03 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAPS_H
# define FT_TERMCAPS_H

# include "libft.h"
# include <termios.h>

# define CTRL_D		0x0004
# define D_QUOTE	0x0022
# define S_QUOTE	0x0027
# define ESCAPE     0x001b
# define ENTER      0x000a
# define K_UP       0x0105
# define K_DOWN     0x0106
# define K_LEFT     0x0107
# define K_RIGHT    0x0108
# define BACKSPACE	0x007F
# define TAB		0x0009

# define DEL		0x0000
# define BCK		0x0001

int		ft_termcaps(char *input);

/*		    Cursor Movement			*/
void	cursor_left(int *cursor);
void	cursor_right(int *cursor);
void	alt_mv_left(int *cursor, char *input);
void	alt_mv_right(int *cursor, char *input, int *bytes);
void	cursor_beginning(int *cur);
void	cursor_end(int *cur, int *bytes);

/*				 Utils				*/
int		get_input(void);
void	print_trail(char *input, int cursor);
void	clear_trail(void);

/*		      BITS Shifting			*/
void	insertion_shift(char *input, int *bytes, int cur);
void	deletion_shift(char *input, int *bytes, int *cur, int mode);

/*		   Input Functions			*/
void	cursor_mv(int *bytes, int *cur, int c);
void	char_print(char *input, int *bytes, int *cur, int c);
void	backspace(char *input, int *bytes, int *cur);
void	delete(char *input, int *bytes, int *cur);
void	esc_parse(char *input, int *bytes, int *cur, int *c);
void	quote_count(int *quote, int *c);
void	init_var(int *c, int *bytes, int *cur, int *quote);

#endif
