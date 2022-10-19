/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:29:54 by mbarutel          #+#    #+#             */
/*   Updated: 2022/10/19 09:34:31 by mbarutel         ###   ########.fr       */
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

void	esc_parse(char *input, t_info *info)
{
	info->ch = get_input();
	if (info->ch == '[')
	{
		info->ch = get_input();
		if (info->ch == 'D')
			info->ch = K_LEFT;
		if (info->ch == 'C')
			info->ch = K_RIGHT;
		if (info->ch == 'H' && info->cursor)
			cursor_beginning(&info->cursor);
		if (info->ch == 'F' && info->cursor < info->bytes)
			cursor_end(&info->cursor, &info->bytes);
		if (info->ch == '1')
			shift(&info->bytes, &info->cursor, &info->ch);
		cursor_mv(&info->bytes, &info->cursor, info->ch);
	}
	if (info->ch == 'b')
		alt_mv_left(&info->cursor, input);
	if (info->ch == 'f')
		alt_mv_right(&info->cursor, input, &info->bytes);
	info->ch = 0;
}
