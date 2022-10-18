/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:29:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/18 14:43:04 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcaps.h"

void	cursor_beginning(int *cur)
{
	write(1, "\033[", 2);
	ft_putnbr(*cur);
	write(1, "D", 1);
	cur[0] = 0;
}

void	cursor_end(int *cur, int *bytes)
{
	write(1, "\033[", 2);
	ft_putnbr(*bytes - *cur);
	write(1, "C", 1);
	cur[0] = *bytes;
}

static void	shift(int *bytes, int *cur, int *c)
{
	c[0] = get_input();
	c[0] = get_input();
	c[0] = get_input();
	if (*c == 'D' && *cur)
		cursor_beginning(cur);
	if (*c == 'C' && *cur < *bytes)
		cursor_end(cur, bytes);
}

void	esc_parse(char *input, int *bytes, int *cur, int *c)
{
	c[0] = get_input();
	if (*c == '[')
	{
		c[0] = get_input();
		// ft_printf("%p\n", c);
		if (*c == 'D')
			*c = K_LEFT;
		if (*c == 'C')
			*c = K_RIGHT;
		if (*c == 'H' && *cur)
			cursor_beginning(cur);
		if (*c == 'F' && *cur < *bytes)
			cursor_end(cur, bytes);
		if (*c == '1')
			shift(bytes, cur, c);
		cursor_mv(bytes, cur, *c);
	}
	if (*c == 'b')
		alt_mv_left(cur, input);
	if (*c == 'f')
		alt_mv_right(cur, input, bytes);
	c[0] = 0;
}
